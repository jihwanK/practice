N, K = map(int, input().split())
arr = [int(input()) for _ in range(N)]

# Please write your code here.
from itertools import combinations

flag = False
for n in range(N, 0, -1):
    comb = list(combinations(arr, n))
    for chosen in comb:
        if max(chosen) - min(chosen) <= K:
            print(n)
            flag = True
            break
    if flag: break
