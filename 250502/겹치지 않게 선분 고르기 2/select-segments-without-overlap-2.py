n = int(input())
# x1, x2 = [], []
lines = []
for _ in range(n):
    a, b = map(int, input().split())
    lines.append((a, b))
    # x1.append(a)
    # x2.append(b)

# Please write your code here.
def is_overlap(l1, l2):
    return l1[1] <= l2[0]

lines.sort(key=lambda x: (x[0], x[1]-x[0]))

dp = [0]*n

dp[0] = 1
for idx, (start, end) in enumerate(lines, start=1):
    print(idx, start, end)