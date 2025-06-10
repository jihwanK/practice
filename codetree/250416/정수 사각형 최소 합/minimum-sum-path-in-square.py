n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
min_sum = [[987654321]*n for _ in range(n)]

min_sum[0][n-1] = grid[0][n-1]

for i in range(1, n):
    min_sum[0][n-1-i] = grid[0][n-1-i] + min_sum[0][n-i]
    min_sum[i][n-1] = grid[i][n-1] + min_sum[i-1][n-1]

for r in range(1, n):
    for c in range(1, n):
        min_sum[r][n-1-c] = grid[r][n-1-c] + min(min_sum[r-1][n-1-c], min_sum[r][n-c])

print(min_sum[n-1][0])
