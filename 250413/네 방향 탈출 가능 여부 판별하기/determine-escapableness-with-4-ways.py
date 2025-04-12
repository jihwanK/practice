n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
from collections import deque

visited = [[False]*m for _ in range(n)]
drs = [-1, 1, 0, 0]
dcs = [0, 0, -1, 1]

def in_range(r, c):
    return 0 <= r < n and 0 <= c < m

def can_go(r, c):
    if not in_range(r, c):
        return False
    if visited[r][c] or a[r][c] == 0:
        return False
    return True

def bfs(r, c):
    global q

    while q:
        r, c = q.popleft()

        for dr, dc in zip(drs, dcs):
            new_r, new_c = r+dr, c+dc
            
            if can_go(new_r, new_c):
                visited[new_r][new_c] = True
                q.append((new_r, new_c))

q = deque([(0, 0)])
visited[0][0] = True
bfs(0, 0)
print(int(visited[n-1][m-1]))
