k, n = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(k)]

# Please write your code here.
from collections import defaultdict

counter = defaultdict(int)
for idx in range(k):
    for i in range(n):
        for j in range(i+1, n):
            counter[(arr[idx][i], arr[idx][j])] += 1

print(len(list(filter(lambda v: v == k, counter.values()))))
