x1, y1, x2, y2 = [0] * 2, [0] * 2, [0] * 2, [0] * 2
x1[0], y1[0], x2[0], y2[0] = map(int, input().split())
x1[1], y1[1], x2[1], y2[1] = map(int, input().split())

# Please write your code here.
offset = 1_000
min_x, max_x = 2_002, -1
min_y, max_y = 2_002, -1
area = [[0]*2_001 for _ in range(2_001)]

# draw
for x in range(offset+x1[0], offset+x2[0]):
    for y in range(offset+y1[0], offset+y2[0]):
        area[x][y] = 1

for x in range(offset+x1[1], offset+x2[1]):
    for y in range(offset+y1[1], offset+y2[1]):
        area[x][y] = 0

# check
for x in range(2_001):
    for y in range(2_001):
        if area[x][y] == 1:
            min_x = min(min_x, x)
            max_x = max(max_x, x)
            min_y = min(min_y, y)
            max_y = max(max_y, y)

if min_x == 2_002 and max_x == -1 and min_y == 2_002 and max_y == -1:
    print(0)
else:
    print((max_x-min_x+1)*(max_y-min_y+1))
