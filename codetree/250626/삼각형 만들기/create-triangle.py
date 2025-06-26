n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]
x = [p[0] for p in points]
y = [p[1] for p in points]

# Please write your code here.
answer = 0
for i in range(n):
    for j in range(n):
        for k in range(n):
            if x[i] == x[j] != x[k] and y[j] == y[k] != y[i]:
                answer = max(answer, abs(y[i]-y[j])*abs(x[j]-x[k]))
print(answer)