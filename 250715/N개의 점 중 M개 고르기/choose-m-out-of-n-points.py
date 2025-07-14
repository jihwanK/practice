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
        answer = min(answer, max([dist(points[selected[i1]], points[selected[i2]]) for i1 in range(m) for i2 in range(i1+1, m)]))
        return

    for p in range(len(points)):
        if p not in selected and (len(selected) == 0 or selected[-1] < p):
            selected.append(p)
            recur(cnt+1)
            selected.pop()

recur(0)
print(answer)