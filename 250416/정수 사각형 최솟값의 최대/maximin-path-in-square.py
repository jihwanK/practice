n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.

max_min = [[0]*n for _ in range(n)]

max_min[0][0] = grid[0][0]
for i in range(1, n):
    max_min[0][i] = min(grid[0][i], max_min[0][i-1])
    max_min[i][0] = min(grid[i][0], max_min[i-1][0])

for r in range(1, n):
    for c in range(1, n):
        # if min(grid[r][c], max_min[r][c-1], max_min[r-1][c]) == grid[r][c]:
        #     max_min[r][c] = grid[r][c]
        # else:
        #     max_min[r][c] = max(max_min[r][c-1], max_min[r-1][c])
        max_min[r][c] = min(grid[r][c], max(max_min[r][c-1], max_min[r-1][c]))

# for row in max_min:
#     print(*row)
print(max_min[n-1][n-1])




### DFS
# def in_range(r, c):
#     return 0 <= r < n and 0 <= c < n

# max_min = -1
# stack = []
# def dfs(r, c, trace):
#     global max_min

#     if (r, c) == (n-1, n-1):
#         max_min = max(max_min, min(trace))
#         return
    
#     if in_range(r+1, c):
#         stack.append((r+1, c))
#         dfs(r+1, c, trace+[grid[r+1][c]])
#         stack.pop()
#     if in_range(r, c+1):
#         stack.append((r, c+1))
#         dfs(r, c+1, trace+[grid[r][c+1]])
#         stack.pop()

# dfs(0, 0, [grid[0][0]])
# print(max_min)