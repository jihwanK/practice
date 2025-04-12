n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
max_val = 0
visited = [False]*n
answer = []
min_max_val = 987654321

def colour(row):
    global max_val
    # global min_max_val

    if row == n:
        max_val = max(max_val, min(answer))
        # min_max_val = min(answer)
        return
    
    for col in range(n):
        if visited[col]:
            continue
        
        visited[col] = True
        answer.append(grid[row][col])
        colour(row+1)
        answer.pop()
        visited[col] = False

colour(0)
print(max_val)
