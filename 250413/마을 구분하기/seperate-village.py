n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
visited = [[0]*n for _ in range(n)]
village = []

drs = [-1, 1, 0, 0]
dcs = [0, 0, -1, 1]

def in_range(r, c):
    return 0 <= r < n and 0 <= c < n

def can_move(r, c):
    if not in_range(r, c):
        return False
    if visited[r][c] == 1 or grid[r][c] == 0:
        return False
    return True

def dfs(r, c):
    global people

    for dr, dc in zip(drs, dcs):
        new_r, new_c = r+dr, c+dc
        
        if can_move(new_r, new_c):
            visited[new_r][new_c] = 1
            dfs(new_r, new_c)
            people += 1
        

for r in range(n):
    for c in range(n):
        if not can_move(r, c):
            continue
        visited[r][c] = 1
        people = 1
        dfs(r, c)
        village.append(people)
print(len(village))
for pop in sorted(village):
    print(pop)