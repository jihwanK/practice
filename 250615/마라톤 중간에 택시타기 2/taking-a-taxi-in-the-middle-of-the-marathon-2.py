n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]
x = [p[0] for p in points]
y = [p[1] for p in points]

# Please write your code here.
min_dist = 1e10
prev = points[0]
for skip_point in points[1:n-1]:
    dist = 0
    for point in points:
        if point != skip_point:
            dist += (abs(point[0]-prev[0]) + abs(point[1]-prev[1]))
            prev = point
    min_dist = min(min_dist, dist)
print(min_dist)