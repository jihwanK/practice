n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]
import sys
sys.setrecursionlimit(2500)
# Please write your code here.
max_safe_area = 0
min_k = 1
drs = [-1, 1, 0, 0]
dcs = [0, 0, -1, 1]

def in_range(r, c):
    return 0 <= r < n and 0 <= c < m

def can_visit(r, c, new_grid):
    if not in_range(r, c):
        return False
    if visited[r][c] == 1 or new_grid[r][c] <= 0:
        return False
    return True

def dfs(r, c, new_grid):
    for dr, dc in zip(drs, dcs):
        new_r, new_c = r+dr, c+dc
        
        if can_visit(new_r, new_c, new_grid):
            visited[new_r][new_c] = 1
            dfs(new_r, new_c, new_grid)


for k in range(1, 101):
    new_grid = [[grid[r][c] for c in range(m)] for r in range(n)]
    for r in range(n):
        for c in range(m):
            new_grid[r][c] = grid[r][c] - k
    
    visited = [[0]*m for _ in range(n)]
    num_safe_area = 0
    for r in range(n):
        for c in range(m):
            if can_visit(r, c, new_grid):
                # print(k, r, c)
                visited[r][c] = 1
                dfs(r, c, new_grid)
                num_safe_area += 1
    
    if max_safe_area < num_safe_area:
        max_safe_area = num_safe_area
        min_k = k

print(min_k, max_safe_area)