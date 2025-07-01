n = int(input())
segments = [tuple(map(int, input().split())) for _ in range(n)]
x1, x2 = zip(*segments)
x1, x2 = list(x1), list(x2)

# Please write your code here.
segments.sort(key=lambda x: (x[0], x[1]))
visited = [0]*101

for line in segments:
    for x in range(line[0], line[1]+1):
        visited[x] += 1

if any(filter(lambda x: x == n, visited)):
    print("Yes")
else:
    print("No")