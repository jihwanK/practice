n, m = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
from collections import deque

visited = [[False]*m for _ in range(n)]
steps = [[1e10]*m for _ in range(n)]
drs = [-1, 1, 0, 0]
dcs = [0, 0, -1, 1]

def can_go(r, c):
    return 0 <= r < n and 0 <= c < m and not visited[r][c] and a[r][c]

def bfs():
    while q:
        r, c = q.popleft()
        
        for dr, dc in zip(drs, dcs):
            new_r, new_c = r+dr, c+dc

            if can_go(new_r, new_c):
                visited[new_r][new_c] = True
                q.append((new_r, new_c))
                if steps[new_r][new_c] > steps[r][c] + 1:
                    steps[new_r][new_c] = steps[r][c] + 1


q = deque([])
q.append((0, 0))
visited[0][0] = True
bfs()
print(steps[n-1][m-1])
print(steps)



