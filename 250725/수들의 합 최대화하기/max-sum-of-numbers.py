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

# def recur(row, col):
def recur(row):
    global answer

    if visited[-1] != -1:
        answer = max(answer, sum([grid[r][c] for r, c in enumerate(visited)]))
        return
    
    for n_col in range(n):
        n_row = row + 1

        if 0 <= n_row < n and can_colour(n_row, n_col):
            visited[n_row] = n_col
            recur(n_row)
            visited[n_row] = -1

recur(-1)
print(answer)