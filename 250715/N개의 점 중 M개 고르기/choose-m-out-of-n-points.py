n, m = map(int, input().split())
points = [tuple(map(int, input().split())) for _ in range(n)]

# Please write your code here.
def dist(p1, p2):
    return (p1[0]-p2[0])**2 + (p1[1]-p2[1])**2

answer = 1e10
selected = []
def recur(cnt):
    global answer

    if cnt == m:
        answer = min(answer, max([dist(selected[i1], selected[i2]) for i1 in range(m) for i2 in range(i1+1, m)]))
        return

    for point in points:
        if point not in selected:
            selected.append(point)
            recur(cnt+1)
            selected.pop()

recur(0)
print(answer)