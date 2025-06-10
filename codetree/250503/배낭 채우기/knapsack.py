N, M = map(int, input().split())
w, v = zip(*[tuple(map(int, input().split())) for _ in range(N)])
w, v = list(w), list(v)
# weight_value = [tuple(map(int, input().split())) for _ in range(N)]
# weight_value.sort(key=lambda x: (-x[1], x[0]))

# Please write your code here.
dp = [[0]*(M+1) for _ in range(N)]

for i in range(1, N):
    for j in range(M+1):
        if j-w[i] >= 0:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i])
        elif j-w[i] < 0:
            dp[i][j] = dp[i-1][j]

ans = 0
for i in range(N):
    ans = max([ans] + dp[i])
print(ans)

