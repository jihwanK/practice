n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
dp = [[-1]*m for _ in range(n)]

dp[0][0] = 1

for r in range(n):
    for c in range(n):
        for nr in range(r):
            for nc in range(c):
                if dp[nr][nc] == -1:
                    continue
                if grid[r][c] > grid[nr][nc]:
                    dp[r][c] = max(dp[r][c], dp[nr][nc]+1)

result = 0
for i in range(n):
    result = max([result]+dp[i])
    # print(*dp[i])

print(result)