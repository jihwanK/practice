"""
필요한 모든 종목/지수의 일별 종가를 FinanceDataReader로 받아 CSV로 캐시한다.
프록시 환경에서 requests 기반 FDR만 동작하므로 yfinance/pykrx 대신 사용.
"""
import os
import warnings
import time
warnings.filterwarnings("ignore")

os.environ.setdefault("REQUESTS_CA_BUNDLE", "/root/.ccr/ca-bundle.crt")
os.environ.setdefault("SSL_CERT_FILE", "/root/.ccr/ca-bundle.crt")

import pandas as pd
import FinanceDataReader as fdr
from snapshots import US_SNAPSHOTS, KR_SNAPSHOTS, all_tickers

HERE = os.path.dirname(os.path.abspath(__file__))
START = "2015-06-01"
END = "2025-06-20"

US_INDICES = {"S&P500": "^GSPC", "NASDAQ": "^IXIC", "DowJones": "^DJI"}
KR_INDICES = {"KOSPI": "KS11", "KOSPI200": "KS200"}  # KOSPI100 무료 소스 없음


def fetch_one(sym):
    for attempt in range(4):
        try:
            d = fdr.DataReader(sym, START, END)
            if d is not None and len(d) > 0 and "Close" in d.columns:
                return d["Close"].rename(sym)
        except Exception as e:
            if attempt == 3:
                print(f"  ! {sym} 실패: {repr(e)[:90]}")
            time.sleep(2 * (attempt + 1))
    return None


def main():
    us_t = all_tickers(US_SNAPSHOTS)
    kr_t = all_tickers(KR_SNAPSHOTS)
    print(f"미국 종목 {len(us_t)}, 한국 종목 {len(kr_t)}, 지수 {len(US_INDICES)+len(KR_INDICES)}")

    cols = {}
    everything = ([(s, "us_stock") for s in us_t]
                  + [(s, "kr_stock") for s in kr_t]
                  + [(v, "idx") for v in US_INDICES.values()]
                  + [(v, "idx") for v in KR_INDICES.values()])
    for i, (sym, _) in enumerate(everything, 1):
        s = fetch_one(sym)
        if s is not None:
            cols[sym] = s
            print(f"  [{i}/{len(everything)}] {sym}: {len(s)} rows")
        else:
            print(f"  [{i}/{len(everything)}] {sym}: NONE")

    df = pd.DataFrame(cols).sort_index()
    out = os.path.join(HERE, "prices.csv")
    df.to_csv(out)
    print(f"\n저장: {out}  shape={df.shape}  {df.index.min().date()}..{df.index.max().date()}")


if __name__ == "__main__":
    main()
