dirs = input()

# Please write your code here.
dx = [0, 1, 0, -1]
dy = [-1, 0, 1, 0]

cur = [0, 0]
toward = 0
for direction in dirs:
    if direction == "L":
        toward = (toward-1+4)%4
    elif direction == "R":
        toward = (toward+1)%4
    elif direction == "F":
        cur[0] += dx[toward]
        cur[1] += dy[toward]

print(cur[0], cur[1])