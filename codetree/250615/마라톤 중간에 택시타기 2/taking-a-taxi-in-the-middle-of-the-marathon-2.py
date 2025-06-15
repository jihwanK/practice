n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]
x = [p[0] for p in points]
y = [p[1] for p in points]

# Please write your code here.
min_dist = 1e10
for i, skip_point in enumerate(points):
    if i == 0: continue
    elif i == n-1: break
    
    prev = points[0]
    dist = 0
    for j, point in enumerate(points):
        if i == 0: continue
        elif i != j:
            dist += (abs(point[0]-prev[0]) + abs(point[1]-prev[1]))
            prev = point
    min_dist = min(min_dist, dist)
print(min_dist)