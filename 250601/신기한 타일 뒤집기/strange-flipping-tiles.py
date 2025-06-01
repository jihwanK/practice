n = int(input())
commands = [tuple(input().split()) for _ in range(n)]
x = []
dir = []
for num, direction in commands:
    x.append(int(num))
    dir.append(direction)

# Please write your code here.
offset = 100_000
left_end, right_end = offset, offset
tiles = [0]*200_001

cur = offset
for i in range(n):
    if dir[i] == "R":
        for delta in range(x[i]):
            tiles[cur+delta] = 1
        cur += x[i]-1
        if cur > right_end:
            right_end = cur
    elif dir[i] == "L":
        for delta in range(x[i]):
            tiles[cur-delta] = -1
        cur -= x[i]-1
        if cur < left_end:
            left_end = cur

w, b = 0, 0
for i in range(left_end, right_end+1):
    if tiles[i] == 1:
        b += 1
    elif tiles[i] == -1:
        w += 1

print(w, b)