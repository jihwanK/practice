n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]
x = [p[0] for p in points]
y = [p[1] for p in points]

# Please write your code here.
answer = 1e10
for xi, yi in zip(x, y):
    for xj, yj in zip(x, y):
        if xi == xj and yi == yj: continue
        answer = min(answer, (xi-xj)**2+(yi-yj)**2)
print(answer)