n = int(input())
grid = [list(input()) for _ in range(n)]
k = int(input())

# Please write your code here.
dr = {"U":-1,"D":1,"R":0,"L":0}
dc = {"L":-1,"R":1,"U":0,"D":0}

def in_range(r, c):
    return 0 <= r < n and 0 <= c < n

if 0 < k <= n:
    (r, c) = (0, k-1)
    direction = "D"
elif n < k <= 2*n:
    (r, c) = (k-1-n, n-1)
    direction = "L"
elif 2*n < k <= 3*n:
    (r, c) = (n-1, 3*n-k)
    direction = "U"
elif 3*n < k <= 4*n:
    (r, c) = (4*n-k, 0)
    direction = "R"

answer = 0
while in_range(r, c):
    # print(r, c, grid[r][c], direction)
    answer += 1
    if grid[r][c] == "/":
        if direction == "D":
            direction = "L"
        elif direction == "L":
            direction = "U"
        elif direction == "U":
            direction = "R"
        elif direction == "R":
            direction = "D"
    elif grid[r][c] == "\\":
        if direction == "D":
            direction = "R"
        elif direction == "R":
            direction = "D"
        elif direction == "U":
            direction = "L"
        elif direction == "L":
            direction = "U"
    
    r, c = r+dr[direction], c+dc[direction]

print(answer)