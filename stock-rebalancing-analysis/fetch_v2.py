"""
v2 데이터 수집: 일별 시가총액(point-in-time 랭킹용) + 조정주가(수익률용)
=====================================================================
방식(미국·한국 대칭): cap(t) = 분할조정가격(t) × 현재주식수
  - 분할조정가격은 분할을 이미 반영 → 분할은 자동 정합. 자사주/증자(주식수 변화)만 미반영(근사).
  - 수익률도 '가격수익'(배당 제외)으로 통일 → 가격지수(S&P500·KOSPI 등)와 공정 비교.
미국:
  - 가격: stockanalysis.com 'c'(분할조정·배당미조정 종가)
  - 현재주식수 N_now = SA overview marketCap / 최근 c
  - cap(t) = c(t) × N_now,  ret(t) = c(t)
한국:
  - 가격: FinanceDataReader Close(분할조정·배당미조정)
  - 현재주식수: FDR StockListing(KOSPI) 의 Stocks
  - cap(t) = close(t) × shares,  ret(t) = close(t)
산출: us_cap.csv, us_ret.csv, kr_cap.csv, kr_ret.csv, kr_universe.csv
"""
import os, time, warnings, json
warnings.filterwarnings("ignore")
os.environ.setdefault("REQUESTS_CA_BUNDLE", "/root/.ccr/ca-bundle.crt")
os.environ.setdefault("SSL_CERT_FILE", "/root/.ccr/ca-bundle.crt")

import numpy as np
import pandas as pd
import requests
import FinanceDataReader as fdr
from universe import US_UNIVERSE

HERE = os.path.dirname(os.path.abspath(__file__))
START = "2015-06-01"
END = "2025-06-20"
UA = "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 Chrome/120 Safari/537.36"
SEC_UA = "research computerandgyein@gmail.com"
KR_TOP_N = 55


def _get(url, headers, timeout=40, tries=4):
    for i in range(tries):
        try:
            r = requests.get(url, headers=headers, timeout=timeout)
            if r.status_code == 200:
                return r
        except Exception:
            pass
        time.sleep(1.5 * (i + 1))
    return None


def sec_cik_map():
    r = _get("https://www.sec.gov/files/company_tickers.json", {"User-Agent": SEC_UA})
    m = r.json()
    return {v["ticker"].upper(): str(v["cik_str"]).zfill(10) for v in m.values()}


def sec_shares(cik, idx):
    """SEC 분기 상장주식수 → 일별 ffill Series (idx에 맞춤)"""
    for concept in ["dei/EntityCommonStockSharesOutstanding",
                    "us-gaap/CommonStockSharesOutstanding"]:
        r = _get(f"https://data.sec.gov/api/xbrl/companyconcept/CIK{cik}/{concept}.json",
                 {"User-Agent": SEC_UA})
        if r is None:
            continue
        try:
            units = r.json()["units"]
            pts = units[list(units)[0]]
        except Exception:
            continue
        rows = {}
        for p in pts:
            if "end" in p and p.get("val"):
                # 같은 end 날짜 여러 값이면 최대값(가장 최근 보고 클래스 합산 근사는 anchor가 보정)
                rows[p["end"]] = max(rows.get(p["end"], 0), int(p["val"]))
        if not rows:
            continue
        s = pd.Series(rows)
        s.index = pd.to_datetime(s.index)
        s = s.sort_index()
        s = s.reindex(idx.union(s.index)).ffill().reindex(idx)
        return s
    return None


def sa_history(ticker):
    """stockanalysis 일별 history → DataFrame[c(raw), a(adj)]"""
    r = _get(f"https://stockanalysis.com/api/symbol/s/{ticker}/history?range=Max",
             {"User-Agent": UA})
    if r is None:
        return None
    j = r.json()

    def find_list(x):
        if isinstance(x, list):
            return x
        if isinstance(x, dict):
            for v in x.values():
                f = find_list(v)
                if f:
                    return f
        return None
    d = find_list(j)
    if not d:
        return None
    df = pd.DataFrame(d)
    df["t"] = pd.to_datetime(df["t"])
    df = df.set_index("t").sort_index()[["c", "a"]].astype(float)
    return df.loc[START:END]


def _parse_suffix(v):
    """'14.69B' / '4.17T' -> float"""
    if v is None:
        return None
    s = str(v).strip().replace(",", "")
    mult = {"T": 1e12, "B": 1e9, "M": 1e6, "K": 1e3}
    if s and s[-1] in mult:
        try:
            return float(s[:-1]) * mult[s[-1]]
        except Exception:
            return None
    try:
        return float(s)
    except Exception:
        return None


def sa_current_shares(ticker):
    """현재 상장주식수 (멀티클래스 통합) from overview.sharesOut"""
    r = _get(f"https://stockanalysis.com/api/symbol/s/{ticker}/overview", {"User-Agent": UA})
    if r is None:
        return None
    d = r.json().get("data", r.json())
    return _parse_suffix(d.get("sharesOut"))


def fetch_us():
    print("== 미국 데이터 (cap = 분할조정가격 × 현재주식수) ==")
    cap_cols, ret_cols = {}, {}
    for i, t in enumerate(US_UNIVERSE, 1):
        hist = sa_history(t)
        if hist is None or len(hist) == 0:
            print(f"  [{i}/{len(US_UNIVERSE)}] {t}: price 없음 SKIP")
            continue
        c = hist["c"].astype(float)          # 분할조정·배당미조정 종가
        ret_cols[t] = c                       # 가격수익(배당 제외)
        n_now = sa_current_shares(t)          # 현재 상장주식수(클래스 통합)
        last_c = c.dropna().iloc[-1]
        if n_now and last_c > 0:
            cap_cols[t] = c * n_now
            print(f"  [{i}/{len(US_UNIVERSE)}] {t}: ok  shares={n_now/1e9:,.2f}B  cap_last={last_c*n_now/1e9:,.0f}B")
        else:
            print(f"  [{i}/{len(US_UNIVERSE)}] {t}: 현재주식수 없음 (cap 제외, 수익률만)")
        time.sleep(0.2)
    cap = pd.DataFrame(cap_cols).sort_index()
    ret = pd.DataFrame(ret_cols).sort_index()
    cap.to_csv(os.path.join(HERE, "us_cap.csv"))
    ret.to_csv(os.path.join(HERE, "us_ret.csv"))
    print(f"  저장 us_cap{cap.shape} us_ret{ret.shape}")


def fetch_kr():
    print("== 한국 데이터 ==")
    lst = fdr.StockListing("KOSPI")
    lst = lst.dropna(subset=["Marcap", "Stocks"])
    # 우선주 제외(본주와 중복 계상 방지): 이름이 '우' 또는 '우B' 등으로 끝나는 종목
    lst = lst[~lst["Name"].str.match(r".+우[0-9A-Z]?$")]
    lst = lst.sort_values("Marcap", ascending=False).head(KR_TOP_N)
    uni = list(lst["Code"])
    shares = dict(zip(lst["Code"], lst["Stocks"]))
    lst[["Code", "Name", "Marcap", "Stocks"]].to_csv(os.path.join(HERE, "kr_universe.csv"), index=False)
    print(f"  KR 유니버스 {len(uni)}종목 (현재 시총 상위)")
    cap_cols, ret_cols = {}, {}
    for i, code in enumerate(uni, 1):
        try:
            d = fdr.DataReader(code, START, END)
            if d is None or len(d) == 0:
                print(f"  [{i}/{len(uni)}] {code}: 없음 SKIP"); continue
            close = d["Close"].astype(float)
            ret_cols[code] = close
            cap_cols[code] = close * float(shares[code])
        except Exception as e:
            print(f"  [{i}/{len(uni)}] {code}: ERR {repr(e)[:60]}")
    cap = pd.DataFrame(cap_cols).sort_index()
    ret = pd.DataFrame(ret_cols).sort_index()
    cap.to_csv(os.path.join(HERE, "kr_cap.csv"))
    ret.to_csv(os.path.join(HERE, "kr_ret.csv"))
    print(f"  저장 kr_cap{cap.shape} kr_ret{ret.shape}")


if __name__ == "__main__":
    fetch_us()
    fetch_kr()
    print("\n완료.")
