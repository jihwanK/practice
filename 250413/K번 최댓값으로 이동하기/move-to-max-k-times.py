n, k = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
start_r, start_c = map(int, input().split())

# Please write your code here.
from collections import deque, defaultdict

visited = [[False]*n for _ in range(n)]
drs = [-1, 1, 0, 0]
dcs = [0, 0, -1, 1]

def move(possibles):
    max_val = max(possibles.keys())
    print(sorted(possibles[max_val], key=lambda x: (x[0], x[1]))[0])
    return sorted(possibles[max_val], key=lambda x: (x[0], x[1]))[0]

def can_go(r, c):
    return 0 <= r < n and 0 <= c < n and not visited[r][c]

def bfs():
    possibles = defaultdict(list)

    while q:
        r, c = q.popleft()

        for dr, dc in zip(drs, dcs):
            new_r, new_c = r+dr, c+dc

            if can_go(new_r, new_c) and grid[r][c] > grid[new_r][new_c]:
                possibles[grid[new_r][new_c]].append((new_r, new_c))
    return possibles

q = deque([])
q.append((start_r-1, start_c-1))
cur = (start_r-1, start_c-1)
visited[start_r-1][start_c-1] = True
for _ in range(k):
    possibles = bfs()
    print(possibles)
    if len(possibles) == 0:
        break
    next_r, next_c = move(possibles)
    visited[next_r][next_c] = True
    q.append((next_r, next_c))

print(cur[0], cur[1])
