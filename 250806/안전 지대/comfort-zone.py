n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
highest = max([max(row) for row in grid])
visited = [[0]*m for _ in range(n)]

def can_go(r, c, k):
    return 0 <= r < n and 0 <= c < m and visited[r][c] == 0 and grid[r][c] > k

drs = [0, 0, 1, -1]
dcs = [1, -1, 0, 0]

def dfs(r, c):
    global k
    
    visited[r][c] = 1

    for dr, dc in zip(drs, dcs):
        nr, nc = r + dr, c + dc

        if can_go(nr, nc, k):
            dfs(nr, nc)

answer_vlg = 0
answer_k = 0
for k in range(highest, 0, -1):
    subanswer = 0
    for r in range(n):
        for c in range(m):
            if can_go(r, c, k):
                dfs(r, c)
                subanswer += 1
    if answer_vlg < subanswer:
        answer_vlg = subanswer
        answer_k = k

print(answer_k, answer_vlg)
        