n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
# answer = [[[0]*n for _ in range(n)] for _ range(n*n)]
answer = -1
dp = [[1]*n for _ in range(n)]
cells = []

def in_range(x, y):
    return 0 <= x < n and 0 <= y < n

for r in range(n):
    for c in range(n):
        cells.append((grid[r][c], r, c))

cells.sort()

drs, dcs = [-1, 1, 0, 0], [0, 0, -1, 1]

for _, r, c in cells:
    for dr, dc in zip(drs, dcs):
        nr, nc = r + dr, c + dc

        if in_range(nr, nc) and grid[nr][nc] > grid[r][c]:
            dp[nr][nc] = max(dp[nr][nc], dp[r][c]+1)
            answer = max(dp[nr][nc], answer)

print(answer)