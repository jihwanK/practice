k, n = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(k)]

# Please write your code here.
from collections import defaultdict

counter = defaultdict(int)
for i in range(k):
    for j in range(n):
        for k in range(j+1, n):
            counter[(arr[i][j], arr[i][k])] += 1

print(len(list(filter(lambda v: v == 3, counter.values()))))