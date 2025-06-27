n = int(input())
lines = [tuple(map(int, input().split())) for _ in range(n)]

# Please write your code here.
def is_intersect(line1, line2):
    if line1[0] < line1[1]:
        if line2[0] < line2[1]:
            return line2[0] < line1[0] < line1[1] < line2[1] \
                or line1[0] < line2[0] < line2[1] < line1[1]
        elif line2[0] > line2[1]:
            return line1[0] < line2[1] < line1[1] < line2[0] \
                or line1[0] < line2[1] < line2[0] < line1[1] \
                or line2[1] < line1[0] < line1[1] < line2[0] \
                or line1[1] < line2[0] < line2[1] < line1[0]
    elif line1[0] > line1[1]:
        if line2[0] < line2[1]:
            return line2[0] < line1[1] < line2[1] < line1[0] \
                or line2[0] < line1[1] < line1[0] < line2[1] \
                or line1[1] < line2[0] < line2[1] < line1[0] \
                or line2[1] < line1[0] < line1[1] < line2[0]
        elif line2[0] > line2[1]:
            return line2[1] < line1[1] < line1[0] < line2[0] \
                or line1[1] < line2[1] < line2[0] < line1[0]

answer = 0
intersect = False
for i in range(n):
    for j in range(n):
        if i != j and is_intersect(lines[i], lines[j]):
            intersect = True
            break
    if not intersect:
        answer += 1
    intersect = False
print(answer)