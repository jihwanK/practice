n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
visited = [[0]*n for _ in range(n)]
answer = []

def can_go(r, c):
    return 0 <= r < n and 0 <= c < n and visited[r][c] == 0 and grid[r][c] == 1

drs = [0, 1, 0, -1]
dcs = [1, 0, -1, 0]

def dfs(r, c):
    global cnt

    if visited[r][c] == 1 or grid[r][c] == 0:
        return

    visited[r][c] = 1
    cnt += 1

    for dr, dc in zip(drs, dcs):
        nr, nc = r + dr, c + dc

        if can_go(nr, nc):
            dfs(nr, nc)

for r in range(n):
    for c in range(n):
        cnt = 0
        dfs(r, c)
        if cnt != 0:
            answer.append(cnt)

answer.sort()
print(len(answer))
for c in answer:
    print(c)