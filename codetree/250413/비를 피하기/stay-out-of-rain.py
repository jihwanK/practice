n, h, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
from collections import deque

shelters = []
humans = []
for r in range(n):
    for c in range(n):
        if grid[r][c] == 3:
            shelters.append((r, c))
        elif grid[r][c] == 2:
            humans.append((r, c))

drs = [-1, 1, 0, 0]
dcs = [0, 0, -1, 1]

def can_go(r, c):
    return 0 <= r < n and 0 <= c < n and grid[r][c] != 1 and not visited[r][c]

def bfs():
    while q:
        r, c = q.popleft()

        for dr, dc in zip(drs, dcs):
            new_r, new_c = r+dr, c+dc
            
            if can_go(new_r, new_c):
                visited[new_r][new_c] = True
                q.append((new_r, new_c))
                steps[new_r][new_c] = steps[r][c] + 1

result = [[0]*n for _ in range(n)]

for human in humans:
    visited = [[False]*n for _ in range(n)]
    steps = [[1e10]*n for _ in range(n)]
    human_r, human_c = human
    steps[human_r][human_c] = 0
    visited[human_r][human_c] = True
    q = deque([(human_r, human_c)])
    bfs()

    shortest = 1e9
    for shelter in shelters:
        shelt_r, shelt_c = shelter
        if steps[shelt_r][shelt_c] < shortest:
            shortest = steps[shelt_r][shelt_c]
    
    if shortest == 1e9:
        result[human_r][human_c] = -1
    else:
        result[human_r][human_c] = shortest

for row in result:
    print(*row)
