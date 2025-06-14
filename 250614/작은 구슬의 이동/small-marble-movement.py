n, t = map(int, input().split())
r, c, d = input().split()
r, c = int(r), int(c)

# Please write your code here.
dx = {"R": 1,"L": -1,"U": 0,"D": 0}
dy = {"U": 1,"D": -1,"R": 0,"L": 0}

def in_range(x, y):
    return 1 <= x <= n and 1 <= y <= n

for _ in range(t):
    nx = c + dx[d]
    ny = r + dy[d]

    if not in_range(nx, ny):
        if d == "R": 
            d = "L"
        elif d == "L":
            d = "R"
        elif d == "U":
            d = "D"
        elif d == "D":
            d = "U"
    else:
        c, r = nx, ny

print(r, c)
