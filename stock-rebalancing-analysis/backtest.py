"""
Top10 가중 리밸런싱 백테스트 엔진
=================================
- 시장: 미국 / 한국
- 가중치: equal(균등) / rank(순위선형 10..1) / mcap(시총근사)
- 리밸런싱 주기: W(매주) / 2W(격주) / M(매월) / Q(분기) / Y(연)
- 거래비용: 리밸런싱 시 turnover * 편도수수료 (US 0.10%, KR 0.15%) 차감
- 멤버십: 리밸런싱 시점이 속한 연도의 시총 Top10 스냅샷 사용 (연 단위 교체 반영)
- 윈도우: 10년(2015-07-01~) / 5년(2020-06-22~), 종료 2025-06-20
"""
import os
import warnings
warnings.filterwarnings("ignore")
os.environ.setdefault("REQUESTS_CA_BUNDLE", "/root/.ccr/ca-bundle.crt")

import numpy as np
import pandas as pd
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

from snapshots import US_SNAPSHOTS, KR_SNAPSHOTS

HERE = os.path.dirname(os.path.abspath(__file__))
PX = pd.read_csv(os.path.join(HERE, "prices.csv"), index_col=0, parse_dates=True).sort_index()

US_IDX = {"S&P500": "^GSPC", "NASDAQ": "^IXIC", "DowJones": "^DJI"}
KR_IDX = {"KOSPI": "KS11", "KOSPI200": "KS200"}

FREQS = {
    "W (매주)": "W-MON",
    "2W (격주)": "2W-MON",
    "M (매월)": "MS",
    "Q (분기)": "QS",
    "Y (연)": "YS",
}
SCHEMES = ["rank", "mcap", "equal"]
SCHEME_KO = {"rank": "순위선형", "mcap": "시총가중", "equal": "균등"}

WINDOWS = {
    "10년": ("2015-07-01", "2025-06-20"),
    "5년": ("2020-06-22", "2025-06-20"),
}


# ----- 가중치 함수 -----
def weights_for(avail, scheme):
    """avail: 시총순 정렬된 [(ticker, cap)] -> {ticker: weight} (합=1)"""
    n = len(avail)
    if scheme == "equal":
        w = {t: 1.0 / n for t, _ in avail}
    elif scheme == "rank":
        raw = {t: (n - i) for i, (t, _) in enumerate(avail)}  # 1위=n ... 꼴찌=1
        s = sum(raw.values())
        w = {t: v / s for t, v in raw.items()}
    elif scheme == "mcap":
        s = sum(c for _, c in avail)
        w = {t: c / s for t, c in avail}
    else:
        raise ValueError(scheme)
    return w


def rebalance_dates(trading_days, freq_code):
    start, end = trading_days[0], trading_days[-1]
    cand = pd.date_range(start, end, freq=freq_code)
    days = []
    for d in cand:
        pos = trading_days.searchsorted(d)
        if pos < len(trading_days):
            days.append(trading_days[pos])
    days = sorted(set(days))
    if not days or days[0] != trading_days[0]:
        days = [trading_days[0]] + days
    return days


def backtest(prices, snapshots, scheme, freq_code, cost_one_way):
    td = prices.index
    rebals = set(rebalance_dates(td, freq_code))
    max_year = max(snapshots)
    value = 1.0
    shares = {}
    out = pd.Series(index=td, dtype=float)
    n_rebals = 0
    total_cost = 0.0
    for day in td:
        px = prices.loc[day]
        if shares:
            value = sum(sh * px[t] for t, sh in shares.items() if pd.notna(px.get(t)))
        if day in rebals:
            members = snapshots.get(day.year, snapshots[max_year])
            avail = [(t, c) for (t, c) in members if t in px.index and pd.notna(px[t]) and px[t] > 0]
            w = weights_for(avail, scheme)
            target = {t: value * wt for t, wt in w.items()}
            keys = set(shares) | set(target)
            current = {t: shares.get(t, 0.0) * (px[t] if pd.notna(px.get(t)) else 0.0) for t in keys}
            turnover = sum(abs(target.get(t, 0.0) - current.get(t, 0.0)) for t in keys)
            cost = turnover * cost_one_way
            total_cost += cost
            value -= cost
            shares = {t: (value * wt) / px[t] for t, wt in w.items()}
            n_rebals += 1
        out[day] = value
    return out, n_rebals, total_cost


def metrics(series):
    start, end = series.index[0], series.index[-1]
    years = (end - start).days / 365.25
    tot = series.iloc[-1] / series.iloc[0] - 1
    cagr = (series.iloc[-1] / series.iloc[0]) ** (1 / years) - 1
    mdd = (series / series.cummax() - 1).min()
    return tot, cagr, mdd, years


def index_series(name_sym, td):
    s = PX[name_sym].reindex(td).ffill().dropna()
    return s / s.iloc[0]


def run_market(market):
    if market == "US":
        snaps, idx, cost = US_SNAPSHOTS, US_IDX, 0.0010
    else:
        snaps, idx, cost = KR_SNAPSHOTS, KR_IDX, 0.0015

    tickers = sorted({t for lst in snaps.values() for t, _ in lst})
    rows = []
    curves = {}  # (window, scheme, freq) -> normalized series
    idx_rows = []

    for wlabel, (ws, we) in WINDOWS.items():
        prices = PX[tickers].loc[ws:we].copy()
        prices = prices.dropna(how="all")
        td = prices.index

        for scheme in SCHEMES:
            for flabel, fcode in FREQS.items():
                series, nreb, tcost = backtest(prices, snaps, scheme, fcode, cost)
                series = series / series.iloc[0]
                tot, cagr, mdd, yrs = metrics(series)
                rows.append(dict(market=market, window=wlabel, scheme=SCHEME_KO[scheme],
                                 scheme_en=scheme, freq=flabel, total_return=tot,
                                 cagr=cagr, mdd=mdd, n_rebal=nreb, cost_drag=tcost))
                curves[(wlabel, scheme, flabel)] = series

        for iname, isym in idx.items():
            iser = index_series(isym, td)
            tot, cagr, mdd, yrs = metrics(iser)
            idx_rows.append(dict(market=market, window=wlabel, index=iname,
                                 total_return=tot, cagr=cagr, mdd=mdd))
            curves[(wlabel, "IDX", iname)] = iser

    return pd.DataFrame(rows), pd.DataFrame(idx_rows), curves, idx


def yearly_table(curves, idx, market):
    """10년 윈도우, 순위선형(rank) 기준 연말 자산가치 + 지수 (시간순 정리용)"""
    wlabel = "10년"
    cols = {}
    for flabel in FREQS:
        cols[flabel] = curves[(wlabel, "rank", flabel)]
    for iname in idx:
        cols[iname] = curves[(wlabel, "IDX", iname)]
    df = pd.DataFrame(cols)
    # 각 연도 마지막 거래일
    ye = df.groupby(df.index.year).tail(1)
    ye.index = [d.year for d in ye.index]
    return ye


def plot_equity(curves, idx, market, scheme, fname):
    wlabel = "10년"
    plt.figure(figsize=(11, 6))
    for flabel in FREQS:
        s = curves[(wlabel, scheme, flabel)]
        plt.plot(s.index, s.values, label=f"Top10 {flabel.split()[0]}", linewidth=1.4)
    for iname in idx:
        s = curves[(wlabel, "IDX", iname)]
        plt.plot(s.index, s.values, "--", label=iname, linewidth=1.1, alpha=0.8)
    plt.yscale("log")
    plt.title(f"{market} Top10 ({scheme}) rebalancing vs indices (10y, growth of 1)")
    plt.ylabel("Growth (log)")
    plt.legend(fontsize=8, ncol=2)
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig(os.path.join(HERE, fname), dpi=110)
    plt.close()


def plot_scheme_compare(curves, idx, market, freq, fname):
    wlabel = "10년"
    plt.figure(figsize=(11, 6))
    for scheme in SCHEMES:
        s = curves[(wlabel, scheme, freq)]
        plt.plot(s.index, s.values, label=f"{scheme}", linewidth=1.5)
    for iname in idx:
        s = curves[(wlabel, "IDX", iname)]
        plt.plot(s.index, s.values, "--", label=iname, linewidth=1.0, alpha=0.7)
    plt.yscale("log")
    plt.title(f"{market} Top10 weighting schemes ({freq.split()[0]} rebal) vs indices (10y)")
    plt.ylabel("Growth (log)")
    plt.legend(fontsize=8, ncol=2)
    plt.grid(True, alpha=0.3)
    plt.tight_layout()
    plt.savefig(os.path.join(HERE, fname), dpi=110)
    plt.close()


def main():
    all_res, all_idx = [], []
    yearlies = {}
    for market in ["US", "KR"]:
        res, idxr, curves, idx = run_market(market)
        all_res.append(res)
        all_idx.append(idxr)
        yearlies[market] = yearly_table(curves, idx, market)
        plot_equity(curves, idx, market, "rank", f"equity_{market.lower()}_rank.png")
        plot_scheme_compare(curves, idx, market, "M (매월)", f"scheme_{market.lower()}_monthly.png")
        print(f"[{market}] 차트/연도표 생성 완료")

    res = pd.concat(all_res, ignore_index=True)
    idxr = pd.concat(all_idx, ignore_index=True)
    res.to_csv(os.path.join(HERE, "results_full.csv"), index=False)
    idxr.to_csv(os.path.join(HERE, "results_index.csv"), index=False)
    for m, y in yearlies.items():
        y.to_csv(os.path.join(HERE, f"yearly_{m.lower()}.csv"))

    pd.set_option("display.width", 200, "display.max_columns", 30)

    def pct(x):
        return f"{x*100:,.1f}%"

    for market in ["US", "KR"]:
        print("\n" + "=" * 78)
        print(f"  {market}  —  Top10 리밸런싱 전략 (윈도우=10년, 2015-07~2025-06)")
        print("=" * 78)
        sub = res[(res.market == market) & (res.window == "10년")]
        piv = sub.pivot_table(index="freq", columns="scheme", values="cagr")
        piv = piv.reindex(list(FREQS.keys()))
        print("\n[연평균수익률 CAGR]")
        print((piv * 100).round(1).to_string())
        pivt = sub.pivot_table(index="freq", columns="scheme", values="total_return").reindex(list(FREQS.keys()))
        print("\n[누적수익률]")
        print((pivt * 100).round(0).astype(int).astype(str).add("%").to_string())
        print("\n[지수 비교 (10년)]")
        si = idxr[(idxr.market == market) & (idxr.window == "10년")]
        for _, r in si.iterrows():
            print(f"   {r['index']:10s}  누적 {pct(r.total_return):>9s}   CAGR {pct(r.cagr):>7s}   MDD {pct(r.mdd):>7s}")
        print("\n[연말 자산가치 — 순위선형 가중, 시작=1.00 (시간순)]")
        print(yearlies[market].round(2).to_string())

    print("\n\n>>> CSV/PNG 저장 완료:", HERE)


if __name__ == "__main__":
    main()
