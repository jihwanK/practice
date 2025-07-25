n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
# visited = [[0]*n for _ in range(n)]

# def can_colour(row, col):
#     for r in range(row):
#         if visited[r].index(1) == col:
#             return False
#     return True

visited = [-1]*n
answer = -1

def can_colour(row, col):
    for r in range(row):
        if visited[r] == col:
            return False
    return True

def recur(row):
    global answer

    if row >= n:
        answer = max(answer, sum([grid[r][c] for r, c in enumerate(visited)]))
        return
    
    for n_col in range(n):
        if can_colour(row, n_col):
            visited[row] = n_col
            recur(row+1)
            visited[row] = -1

recur(0)
print(answer)