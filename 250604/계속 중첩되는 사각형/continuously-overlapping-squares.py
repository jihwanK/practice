n = int(input())
x1, y1, x2, y2 = [], [], [], []
for _ in range(n):
    a, b, c, d = map(int, input().split())
    x1.append(a)
    y1.append(b)
    x2.append(c)
    y2.append(d)

# Please write your code here.
offset = 100
area = [[0]*201 for _ in range(201)]

for i in range(n):
    for x in range(offset+x1[i], offset+x2[i]):
        for y in range(offset+y1[i], offset+y2[i]):
            if i%2 == 0:
                area[x][y] = 0 #red
            else:
                area[x][y] = 1 #blue

answer = 0
for row in area:
    answer += sum(row)
print(answer)