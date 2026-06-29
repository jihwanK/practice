"""
v2 후보 유니버스 (point-in-time 시총 랭킹용)
============================================
생존편향을 줄이기 위해, 2015~2025 사이 한때 시총 상위권이었던 종목
(GE·인텔·엑손·화이자·시스코 등 "쇠락한 거인" 포함)을 폭넓게 넣는다.
실제 Top10은 매 리밸런싱일 cap으로 다시 계산되므로, 유니버스는 "충분히 넓기만"
하면 된다(진짜 Top10을 항상 포함하도록).
"""

# 미국 후보 (SEC CIK로 과거 주식수 조회 가능한 미국 상장사)
US_UNIVERSE = [
    "AAPL", "MSFT", "GOOGL", "AMZN", "NVDA", "META", "TSLA", "BRK-B", "LLY", "AVGO",
    "JPM", "V", "UNH", "XOM", "JNJ", "WMT", "MA", "PG", "HD", "COST",
    "ORCL", "MRK", "ABBV", "CVX", "KO", "PEP", "BAC", "ADBE", "CRM", "NFLX",
    "AMD", "TMO", "MCD", "CSCO", "ACN", "ABT", "WFC", "DIS", "INTC", "IBM",
    "GE", "CMCSA", "VZ", "T", "PFE", "NKE", "QCOM", "TXN", "PM", "HON",
    "UPS", "GS", "CAT", "BA", "MMM", "C", "AMGN", "BMY", "LOW", "INTU",
]

US_NAMES = {
    "AAPL": "Apple", "MSFT": "Microsoft", "GOOGL": "Alphabet", "AMZN": "Amazon",
    "NVDA": "NVIDIA", "META": "Meta", "TSLA": "Tesla", "BRK-B": "Berkshire",
    "LLY": "EliLilly", "AVGO": "Broadcom", "JPM": "JPMorgan", "V": "Visa",
    "UNH": "UnitedHealth", "XOM": "ExxonMobil", "JNJ": "J&J", "WMT": "Walmart",
    "MA": "Mastercard", "PG": "P&G", "HD": "HomeDepot", "COST": "Costco",
    "ORCL": "Oracle", "MRK": "Merck", "ABBV": "AbbVie", "CVX": "Chevron",
    "KO": "CocaCola", "PEP": "PepsiCo", "BAC": "BofA", "ADBE": "Adobe",
    "CRM": "Salesforce", "NFLX": "Netflix", "AMD": "AMD", "TMO": "ThermoFisher",
    "MCD": "McDonalds", "CSCO": "Cisco", "ACN": "Accenture", "ABT": "Abbott",
    "WFC": "WellsFargo", "DIS": "Disney", "INTC": "Intel", "IBM": "IBM",
    "GE": "GE", "CMCSA": "Comcast", "VZ": "Verizon", "T": "AT&T",
    "PFE": "Pfizer", "NKE": "Nike", "QCOM": "Qualcomm", "TXN": "TexasInstr",
    "PM": "PhilipMorris", "HON": "Honeywell", "UPS": "UPS", "GS": "Goldman",
    "CAT": "Caterpillar", "BA": "Boeing", "MMM": "3M", "C": "Citi",
    "AMGN": "Amgen", "BMY": "BMS", "LOW": "Lowes", "INTU": "Intuit",
}

# 한국 유니버스는 fetch_v2.py 에서 FDR StockListing(KOSPI) 상위 N개를 동적으로 선정해
# kr_universe.csv 로 저장한다(재현용). 여기서는 이름 보강만.
KR_NAMES = {
    "005930": "삼성전자", "000660": "SK하이닉스", "006400": "삼성SDI", "051910": "LG화학",
    "035420": "NAVER", "005380": "현대차", "035720": "카카오", "068270": "셀트리온",
    "207940": "삼성바이오로직스", "005490": "POSCO홀딩스", "000270": "기아",
    "012330": "현대모비스", "032830": "삼성생명", "090430": "아모레퍼시픽",
    "017670": "SK텔레콤", "028260": "삼성물산", "105560": "KB금융", "055550": "신한지주",
    "373220": "LG에너지솔루션", "005935": "삼성전자우", "051900": "LG생활건강",
    "066570": "LG전자", "096770": "SK이노베이션", "034730": "SK", "015760": "한국전력",
    "003550": "LG", "018260": "삼성에스디에스", "009150": "삼성전기", "010130": "고려아연",
    "011200": "HMM", "323410": "카카오뱅크", "086790": "하나금융지주", "316140": "우리금융지주",
    "000810": "삼성화재", "030200": "KT", "033780": "KT&G", "024110": "기업은행",
    "010950": "S-Oil", "402340": "SK스퀘어", "259960": "크래프톤", "036570": "엔씨소프트",
    "352820": "하이브", "047810": "한국항공우주", "012450": "한화에어로스페이스",
    "042660": "한화오션", "329180": "HD현대중공업", "267260": "HD현대일렉트릭",
    "064350": "현대로템", "010140": "삼성중공업", "011070": "LG이노텍",
}
