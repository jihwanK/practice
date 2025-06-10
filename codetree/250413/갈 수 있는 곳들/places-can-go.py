n, k = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
points = [tuple(map(int, input().split())) for _ in range(k)]

# Please write your code here.
from collections import deque

visited = [[False]*n for _ in range(n)]
area = 0
drs = [-1, 1, 0, 0]
dcs = [0, 0, -1, 1]


def can_go(r, c):
    return 0 <= r < n and 0 <= c < n and not visited[r][c] and grid[r][c] == 0

q = deque()

def bfs():
    global area

    while q:
        r, c = q.popleft()
        for dr, dc in zip(drs, dcs):
            new_r, new_c = r+dr, c+dc
            
            if can_go(new_r, new_c):
                visited[new_r][new_c] = True
                q.append((new_r, new_c))

for point in points:
    q.append((point[0]-1,point[1]-1))
    visited[point[0]-1][point[1]-1] = True
    bfs()

print(sum([sum(row) for row in visited]))