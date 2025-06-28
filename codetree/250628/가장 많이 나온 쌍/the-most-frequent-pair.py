n, m = map(int, input().split())
pairs = [tuple(map(int, input().split())) for _ in range(m)]

# Please write your code here.
from collections import Counter, defaultdict

answer = 0
counter = defaultdict(int)
for pair in pairs:
    a, b = pair
    counter[(a, b)] += 1
    counter[(b, a)] += 1

    answer = max(answer, counter[(a, b)])
    answer = max(answer, counter[(b, a)])

print(answer)