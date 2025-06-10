n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
max_sum = [[0]*n for _ in range(n)]

max_sum[0][0] = grid[0][0]

for i in range(1, n):
    max_sum[0][i] = max_sum[0][i-1] + grid[0][i]
    max_sum[i][0] = max_sum[i-1][0] + grid[i][0]

for r in range(1, n):
    for c in range(1, n):
        max_sum[r][c] = grid[r][c] + max(max_sum[r-1][c], max_sum[r][c-1])

print(max_sum[n-1][n-1])