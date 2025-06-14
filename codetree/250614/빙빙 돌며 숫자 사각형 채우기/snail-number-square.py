n, m = map(int, input().split())
arr = [[0] * m for _ in range(n)]

# Please write your code here.
dc = [1, 0, -1, 0]
dr = [0, 1, 0, -1]

def in_range(r, c):
    return 0 <= c < m and 0 <= r < n

num = 1
direction = 0
r, c = 0, 0
arr[r][c] = num
while num < n*m:
    nr = r + dr[direction]
    nc = c + dc[direction]

    if not in_range(nr, nc) or arr[nr][nc] != 0:
        direction = (direction+1) % 4
    else:
        r, c = nr, nc
        num += 1
        arr[r][c] = num

for row in arr:
    print(*row)
    
