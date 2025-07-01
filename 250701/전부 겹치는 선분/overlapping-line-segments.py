n = int(input())
segments = [tuple(map(int, input().split())) for _ in range(n)]
x1, x2 = zip(*segments)
x1, x2 = list(x1), list(x2)

# Please write your code here.
segments.sort(key=lambda x: (x[0], x[1]))

overlapped = False
prev = segments[0]
for cur in segments[1:]:
    if prev[1] >= cur[0]:
        overlapped = True
        break

if overlapped:
    print("Yes")
else:
    print("No")