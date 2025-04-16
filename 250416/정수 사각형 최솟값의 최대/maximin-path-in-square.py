n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.

def in_range(r, c):
    return 0 <= r < n and 0 <= c < n

max_min = -1
stack = []
def dfs(r, c, trace):
    global max_min

    if (r, c) == (n-1, n-1):
        # print(trace)
        max_min = max(max_min, min(trace))
        return
    
    if in_range(r+1, c):
        stack.append((r+1, c))
        dfs(r+1, c, trace+[grid[r+1][c]])
        stack.pop()
    if in_range(r, c+1):
        stack.append((r, c+1))
        dfs(r, c+1, trace+[grid[r][c+1]])
        stack.pop()

dfs(0, 0, [grid[0][0]])
print(max_min)