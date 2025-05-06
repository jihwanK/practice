n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
from copy import deepcopy
# new_grid = deepcopy(grid)

def bomb_range(r, c):
    bomb_range_list = []
    power = new_grid[r][c]
    bomb_range_list.append((r, c))
    for i in range(1, power):
        if 0 <= r+i < n:
            bomb_range_list.append((r+i, c))
        if 0 <= r-i < n:
            bomb_range_list.append((r-i, c))
        if 0 <= c+i < n:
            bomb_range_list.append((r, c+i))
        if 0 <= c-i < n:
            bomb_range_list.append((r, c-i))
    return bomb_range_list


def bombard(bomb_range_list):
    for b_range in bomb_range_list:
        r, c = b_range
        new_grid[r][c] = 0
    
    # gravity
    for g_c in range(n):
        for g_r in range(n-1, 0, -1):
            if new_grid[g_r][g_c] == 0:
                new_grid[g_r][g_c] = new_grid[g_r-1][g_c]
                new_grid[g_r-1][g_c] = 0


def count_pair():
    count = 0
    for r in range(n):
        for c in range(n):
            if new_grid[r][c] != 0:
                for dr, dc in zip([0, 1], [1, 0]):
                    nr, nc = r+dr, c+dc
                    if 0 <= nr < n and 0 <= nc < n:
                        if new_grid[r][c] == new_grid[nr][nc]:
                            count += 1
    return count

answer = 0
for r in range(n):
    for c in range(n):
        new_grid = deepcopy(grid)
        bomb_range_list = bomb_range(r, c)
        bombard(bomb_range_list)
        answer = max(answer, count_pair())
        # if (r,c) == (2,1):
        #     print(f"[{(r, c)}] power: {grid[r][c]}, {bomb_range_list}")
        #     for row in new_grid:
        #         print(*row)
        #     print()
print(answer)

