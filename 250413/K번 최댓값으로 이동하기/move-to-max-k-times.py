n, k = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
r, c = map(int, input().split())

# Please write your code here.
from collections import deque

visited = [[False]*n for _ in range(n)]
drs = [-1, 1, 0, 0]
dcs = [0, 0, -1, 1]

def can_go(r, c):
    return 0 <= r < n and 0 <= c < n and not visited[r][c]

def bfs():
    while q:
        r, c = q.popleft()

        for dr, dc in zip(drs, dcs):
            new_r, new_c = r+dr, c+dc



q = deque()

for _ in range(k):
    bfs()