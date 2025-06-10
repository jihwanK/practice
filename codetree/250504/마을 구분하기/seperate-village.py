n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
visited = [[0]*n for _ in range(n)]
drs, dcs = [0, 0, 1, -1], [1, -1, 0, 0]

def in_range(r, c):
    return 0 <= r < n and 0 <= c < n

def can_go(r, c):
    return in_range(r, c) and grid[r][c] == 1 and visited[r][c] == 0

def dfs(r, c):
    global residents

    for dr, dc in zip(drs, dcs):
        nr, nc = r+dr, c+dc
        if can_go(nr, nc):
            residents += 1
            visited[nr][nc] = 1
            dfs(nr, nc)

village = []
for r in range(n):
    for c in range(n):
        if can_go(r, c):
            residents = 1
            visited[r][c] = 1
            dfs(r, c)
            village.append(residents)

print(len(village))
for resdnt in sorted(village):
    print(resdnt)