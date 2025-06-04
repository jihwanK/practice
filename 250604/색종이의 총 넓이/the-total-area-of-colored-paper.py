n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]
x, y = zip(*points)
x, y = list(x), list(y)

# Please write your code here.
offset = 100
area = [[0]*201 for _ in range(201)]
size = 8

for i in range(n):
    for nx in range(offset+x[i], offset+x[i]+size):
        for ny in range(offset+y[i], offset+y[i]+size):
            area[nx][ny] = 1

answer = 0
for row in area:
    answer += sum(row)

print(answer)
