"""
v2 백테스트: 매 리밸런싱일에 '그 날 시가총액'으로 Top10을 새로 선정
====================================================================
- 진짜 point-in-time 멤버십 (주/격주/월/분기/연 시점마다 Top10 재계산)
- 가중: rank(순위선형) / mcap(실제 cap 비례) / equal(균등)
- 거래비용: US 0.10% / KR 0.15% (편도, turnover 기준)
- 윈도우: 10년(2015-07~) / 5년(2020-06~), 종료 2025-06-20
- 지수: prices.csv 재사용
"""
import os, warnings
warnings.filterwarnings("ignore")
import numpy as np
import pandas as pd
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from universe import US_NAMES, KR_NAMES

HERE = os.path.dirname(os.path.abspath(__file__))
IDXPX = pd.read_csv(os.path.join(HERE, "prices.csv"), index_col=0, parse_dates=True).sort_index()
US_IDX = {"S&P500": "^GSPC", "NASDAQ": "^IXIC", "DowJones": "^DJI"}
KR_IDX = {"KOSPI": "KS11", "KOSPI200": "KS200"}
FREQS = {"W (매주)": "W-MON", "2W (격주)": "2W-MON", "M (매월)": "MS", "Q (분기)": "QS", "Y (연)": "YS"}
SCHEMES = ["rank", "mcap", "equal"]
SCHEME_KO = {"rank": "순위선형", "mcap": "시총가중", "equal": "균등"}
WINDOWS = {"10년": ("2015-07-01", "2025-06-20"), "5년": ("2020-06-22", "2025-06-20")}
TOPN = 10


def rebalance_dates(td, code):
    cand = pd.date_range(td[0], td[-1], freq=code)
    days = []
    for d in cand:
        pos = td.searchsorted(d)
        if pos < len(td):
            days.append(td[pos])
    days = sorted(set(days))
    if not days or days[0] != td[0]:
        days = [td[0]] + days
    return days


def weights(members_caps, scheme):
    """members_caps: cap 내림차순 [(ticker, cap)] (이미 top10) -> {t:w}"""
    n = len(members_caps)
    if scheme == "equal":
        return {t: 1.0 / n for t, _ in members_caps}
    if scheme == "rank":
        raw = {t: (n - i) for i, (t, _) in enumerate(members_caps)}
        s = sum(raw.values())
        return {t: v / s for t, v in raw.items()}
    if scheme == "mcap":
        s = sum(c for _, c in members_caps)
        return {t: c / s for t, c in members_caps}
    raise ValueError(scheme)


def backtest(cap, ret, scheme, code, cost):
    td = ret.index
    rebals = set(rebalance_dates(td, code))
    value, shares = 1.0, {}
    out = pd.Series(index=td, dtype=float)
    nreb, tcost = 0, 0.0
    picks = {}  # date -> [tickers]
    for day in td:
        px = ret.loc[day]
        if shares:
            value = sum(sh * px[t] for t, sh in shares.items() if pd.notna(px.get(t)))
        if day in rebals:
            capday = cap.loc[day]
            avail = [(t, capday[t]) for t in cap.columns
                     if pd.notna(capday.get(t)) and capday[t] > 0
                     and pd.notna(px.get(t)) and px[t] > 0]
            avail.sort(key=lambda x: x[1], reverse=True)
            top = avail[:TOPN]
            w = weights(top, scheme)
            target = {t: value * wt for t, wt in w.items()}
            keys = set(shares) | set(target)
            cur = {t: shares.get(t, 0.0) * (px[t] if pd.notna(px.get(t)) else 0.0) for t in keys}
            turn = sum(abs(target.get(t, 0.0) - cur.get(t, 0.0)) for t in keys)
            c = turn * cost
            tcost += c; value -= c
            shares = {t: (value * wt) / px[t] for t, wt in w.items()}
            nreb += 1
            picks[day] = [t for t, _ in top]
        out[day] = value
    return out, nreb, tcost, picks


def metrics(s):
    yrs = (s.index[-1] - s.index[0]).days / 365.25
    tot = s.iloc[-1] / s.iloc[0] - 1
    cagr = (s.iloc[-1] / s.iloc[0]) ** (1 / yrs) - 1
    mdd = (s / s.cummax() - 1).min()
    return tot, cagr, mdd


def idx_series(sym, td):
    s = IDXPX[sym].reindex(td).ffill().dropna()
    return s / s.iloc[0]


def run_market(market):
    if market == "US":
        cap = pd.read_csv(os.path.join(HERE, "us_cap.csv"), index_col=0, parse_dates=True)
        ret = pd.read_csv(os.path.join(HERE, "us_ret.csv"), index_col=0, parse_dates=True)
        idx, cost, names = US_IDX, 0.0010, US_NAMES
    else:
        cap = pd.read_csv(os.path.join(HERE, "kr_cap.csv"), index_col=0, parse_dates=True)
        ret = pd.read_csv(os.path.join(HERE, "kr_ret.csv"), index_col=0, parse_dates=True)
        cap.columns = [str(c).zfill(6) for c in cap.columns]
        ret.columns = [str(c).zfill(6) for c in ret.columns]
        idx, cost, names = KR_IDX, 0.0015, KR_NAMES
    cap = cap.sort_index(); ret = ret.sort_index()

    rows, curves, idx_rows = [], {}, []
    membership = {}
    for wl, (ws, we) in WINDOWS.items():
        r = ret.loc[ws:we].dropna(how="all")
        c = cap.reindex(r.index)[ [col for col in cap.columns if col in r.columns] ]
        td = r.index
        for scheme in SCHEMES:
            for fl, fc in FREQS.items():
                s, nr, tc, picks = backtest(c, r, scheme, fc, cost)
                s = s / s.iloc[0]
                tot, cagr, mdd = metrics(s)
                rows.append(dict(market=market, window=wl, scheme=SCHEME_KO[scheme],
                                 scheme_en=scheme, freq=fl, total_return=tot, cagr=cagr,
                                 mdd=mdd, n_rebal=nr, cost_drag=tc))
                curves[(wl, scheme, fl)] = s
                if wl == "10년" and scheme == "rank" and fc == "YS":
                    membership = picks
        for nm, sym in idx.items():
            isr = idx_series(sym, td)
            tot, cagr, mdd = metrics(isr)
            idx_rows.append(dict(market=market, window=wl, index=nm, total_return=tot, cagr=cagr, mdd=mdd))
            curves[(wl, "IDX", nm)] = isr
    return pd.DataFrame(rows), pd.DataFrame(idx_rows), curves, idx, names, membership


def yearly_table(curves, idx):
    cols = {fl: curves[("10년", "rank", fl)] for fl in FREQS}
    for nm in idx:
        cols[nm] = curves[("10년", "IDX", nm)]
    df = pd.DataFrame(cols)
    ye = df.groupby(df.index.year).tail(1)
    ye.index = [d.year for d in ye.index]
    return ye


def plot_equity(curves, idx, market, fname):
    plt.figure(figsize=(11, 6))
    for fl in FREQS:
        s = curves[("10년", "rank", fl)]
        plt.plot(s.index, s.values, label=f"Top10 {fl.split()[0]}", lw=1.4)
    for nm in idx:
        s = curves[("10년", "IDX", nm)]
        plt.plot(s.index, s.values, "--", label=nm, lw=1.1, alpha=0.8)
    plt.yscale("log"); plt.title(f"{market} v2 point-in-time Top10 (rank) vs indices (10y)")
    plt.ylabel("Growth (log)"); plt.legend(fontsize=8, ncol=2); plt.grid(True, alpha=0.3)
    plt.tight_layout(); plt.savefig(os.path.join(HERE, fname), dpi=110); plt.close()


def main():
    allr, alli, yearlies, memb = [], [], {}, {}
    for market in ["US", "KR"]:
        res, idxr, curves, idx, names, membership = run_market(market)
        allr.append(res); alli.append(idxr)
        yearlies[market] = yearly_table(curves, idx)
        memb[market] = (membership, names)
        plot_equity(curves, idx, market, f"v2_equity_{market.lower()}.png")
        print(f"[{market}] 완료")

    res = pd.concat(allr, ignore_index=True); idxr = pd.concat(alli, ignore_index=True)
    res.to_csv(os.path.join(HERE, "v2_results_full.csv"), index=False)
    idxr.to_csv(os.path.join(HERE, "v2_results_index.csv"), index=False)
    for m, y in yearlies.items():
        y.to_csv(os.path.join(HERE, f"v2_yearly_{m.lower()}.csv"))

    for market in ["US", "KR"]:
        print("\n" + "=" * 78)
        print(f"  {market}  v2 (진짜 시점별 Top10) — 10년")
        print("=" * 78)
        sub = res[(res.market == market) & (res.window == "10년")]
        piv = sub.pivot_table(index="freq", columns="scheme", values="cagr").reindex(list(FREQS))
        print("\n[CAGR %]"); print((piv * 100).round(1).to_string())
        si = idxr[(idxr.market == market) & (idxr.window == "10년")]
        print("\n[지수]")
        for _, r in si.iterrows():
            print(f"   {r['index']:10s} 누적 {r.total_return*100:7.1f}%  CAGR {r.cagr*100:5.1f}%  MDD {r.mdd*100:6.1f}%")
        print("\n[연도별 실제 Top10 (rank, 연 리밸런싱) — 멤버십 변천]")
        membership, names = memb[market]
        for d in sorted(membership):
            nm = [names.get(t, t) for t in membership[d]]
            print(f"   {d.year}: {', '.join(nm)}")
    print("\n>>> v2 산출물 저장:", HERE)


if __name__ == "__main__":
    main()
