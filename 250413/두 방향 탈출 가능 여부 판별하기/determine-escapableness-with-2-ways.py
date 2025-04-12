n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
def in_range(r, c):
    return 0 <= r < n and 0 <= c < m

def can_go(r, c):
    if not in_range(r, c):
        return False
    if grid[r][c] == 0 or visited[r][c]:
        return False
    return True

visited = [[False]*m for _ in range(n)]
drs = [1, 0]
dcs = [0, 1]
answer = []

def dfs(r, c):
    if (r, c) == (n-1, m-1):
        # print(answer)
        return
    
    for dr, dc in zip(drs, dcs):
        new_r, new_c = r+dr, c+dc
        # if not in_range(new_r, new_c):
        #     continue
        
        if can_go(new_r, new_c):
            visited[new_r][new_c] = True
            answer.append((new_r, new_c))
            dfs(new_r, new_c)


visited[0][0] = True
answer.append((0, 0))
dfs(0, 0)
print(int((n-1, m-1) in answer))
# print(answer)