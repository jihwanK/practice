n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
dxs = [0, 0, -1, 1]
dys = [1, -1, 0, 0]
answer = 0

def in_range(x, y):
    return 0 <= x < n and 0 <= y < n

for y in range(n):
    for x in range(n):
        if in_range(x, y):
            count = 0
            for dx, dy in zip(dxs, dys):
                nx = x + dx
                ny = y + dy

                if in_range(nx, ny) and grid[ny][nx] == 1:
                    count += 1
        
        if count >= 3:
            answer += 1

print(answer)