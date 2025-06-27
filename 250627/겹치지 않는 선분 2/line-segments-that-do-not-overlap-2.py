n = int(input())
lines = [tuple(map(int, input().split())) for _ in range(n)]

# Please write your code here.
def is_intersect(line1, line2):
    return (line1[0] < line2[0] < line1[1] and line1[0] < line2[1] < line1[1]) \
    or (line2[0] < line1[0] < line2[1] and line2[0] < line1[1] < line2[1])

answer = 0
intersect = False
for i in range(n):
    for j in range(n):
        if is_intersect(lines[i], lines[j]):
            intersect = True
    if not intersect:
        answer += 1
    intersect = False
print(answer)