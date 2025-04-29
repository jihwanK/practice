n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
result = [[0]*n for _ in range(n)]

result[0][0] = grid[0][0]
for i in range(1, n):
    result[0][i] = max(grid[0][i], result[0][i-1])
    result[i][0] = max(grid[i][0], result[i-1][0])

for r in range(1, n):
    for c in range(1, n):
        result[r][c] = max(grid[r][c], min(result[r][c-1], result[r-1][c]))

print(result[-1][-1])