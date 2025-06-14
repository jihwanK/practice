n, m = map(int, input().split())
points = [tuple(map(int, input().split())) for _ in range(m)]

# Please write your code here.
drs = [0, 0, 1, -1]
dcs = [1, -1, 0, 0]

def in_range(r, c):
    return 1 <= r <= n and 1 <= c <= m

grid = [[0]*(m+1) for _ in range(n+1)]
for (r, c) in points:
    grid[r][c] = 1
    
    cnt = 0
    for dr, dc in zip(drs, dcs):
        nr, nc = r + dr, c + dc
        if in_range(nr, nc) and grid[nr][nc] == 1:
            cnt += 1
    if cnt == 3:
        print(1)
    else:
        print(0)
