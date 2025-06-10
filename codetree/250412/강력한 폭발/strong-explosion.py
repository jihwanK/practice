n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
bombs = {
    1: [(-2, 0), (-1, 0), (0, 0), (1, 0), (2, 0)],
    2: [(-1, 0), (1, 0), (0, 0), (0, -1), (0, 1)],
    3: [(-1, -1), (-1, 1), (0, 0), (1, -1), (1, 1)],
}

new_grid = [[0]*n for _ in range(n)]

targets = [(r, c) for r in range(n) for c in range(n) if grid[r][c] == 1]
num_tagets = len(targets)
max_damage = 0
bomb_list = []

def in_range(r, c):
    return 0 <= r < n and 0 <= c < n

def count_destroyed_area(grid):
    cnt = 0
    for r in range(n):
        for c in range(n):
            if grid[r][c] == -1: 
                cnt += 1
    return cnt

def explode(grid, targets, bomb_list):
    for target, bomb in zip(targets, bomb_list):
        for bomb_area in bomb:
            if in_range(target[0]+bomb_area[0], target[1]+bomb_area[1]):
                grid[target[0]+bomb_area[0]][target[1]+bomb_area[1]] = -1
    return grid


def bombard(cnt_tagets):
    global max_damage
    
    new_grid = [[0]*n for _ in range(n)]
    if cnt_tagets == num_tagets:
        new_grid = explode(new_grid, targets, bomb_list)
        max_damage = max(max_damage, count_destroyed_area(new_grid))
        return
    
    for i, bomb in bombs.items():
        bomb_list.append(bomb)
        bombard(cnt_tagets+1)
        bomb_list.pop()
    
    return
    

bombard(0)
print(max_damage)