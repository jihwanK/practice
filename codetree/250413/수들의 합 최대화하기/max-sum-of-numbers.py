n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
selected_col = [False]*n
answer = []
max_value = 0

def colour(row):
    global max_value

    if row == n:
        # print(answer)
        max_value = max(max_value, sum(answer))
        return
    

    for col in range(n):
        if selected_col[col]:
            continue
        selected_col[col] = True
        answer.append(grid[row][col])
        colour(row+1)
        answer.pop()
        selected_col[col] = False

colour(0)
print(max_value)
