import math

def get_series(n, m, answer_series):
  for i in range(n - m  + 1):
    res = 1
    for ele in range(i + 1, m + i + 1):
      res *= ele
    answer_series.add(res)

  return answer_series

def sol(n):
  answer_series = set()
  
  semi = math.floor(math.sqrt(2 * n))
  
  sq = 0

  if semi * (semi - 1) / 2 < n <= (semi + 1) * semi / 2:
    sq = semi + 2
  elif (semi - 1) * (semi - 2) / 2 < n <= semi * (semi - 1) / 2:
    sq = semi + 1
  elif (semi - 2) * (semi - 3) / 2 < n <= (semi - 1) * (semi - 2) / 2:
    sq = semi
  elif (semi - 3) * (semi - 4) / 2 < n <= (semi - 2) * (semi - 3) / 2:
    sq = semi - 1
  
  
  for i in range(2, n):
    get_series(sq, i, answer_series)
  
  print(answer_series)
  print(list(sorted(answer_series))[n-1])

  


sol(5)