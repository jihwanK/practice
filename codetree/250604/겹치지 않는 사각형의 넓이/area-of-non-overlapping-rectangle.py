x1 = [0] * 3
y1 = [0] * 3
x2 = [0] * 3
y2 = [0] * 3

x1[0], y1[0], x2[0], y2[0] = map(int, input().split())
x1[1], y1[1], x2[1], y2[1] = map(int, input().split())
x1[2], y1[2], x2[2], y2[2] = map(int, input().split())

# Please write your code here.
offset = 1_000
area = [[0]*2001 for _ in range(2001)]

for i in range(2):
    for x in range(offset+x1[i], offset+x2[i]):
        for y in range(offset+y1[i], offset+y2[i]):
            area[x][y] = 1

for x in range(offset+x1[2], offset+x2[2]):
    for y in range(offset+y1[2], offset+y2[2]):
        area[x][y] = 0

answer = 0
for row in area:
    answer += sum(row)

print(answer)