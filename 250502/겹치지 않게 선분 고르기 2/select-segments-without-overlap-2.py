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
    return l1[1] >= l2[0]

lines.sort(key=lambda x: (x[0], x[1]))

dp = [1]*n

dp[0] = 1
for i, (start_i, end_i) in enumerate(lines[1:], start=1):
    l1 = (start_i, end_i)
    for j, (start_j, end_j) in enumerate(lines[:i]):
        l2 = (start_j, end_j)

        if not is_overlap(l2, l1):
            dp[i] = max(dp[j]+1, dp[i])

print(max(dp))