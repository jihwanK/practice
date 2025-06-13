n = int(input())
moves = [tuple(input().split()) for _ in range(n)]
dir = [move[0] for move in moves]
dist = [int(move[1]) for move in moves]

# Please write your code here.
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
cur = [0, 0]

for direction, distance in zip(dir, dist):
    if direction == "N":
        cur[0] += distance*dx[0]
        cur[1] += distance*dy[0]
    elif direction == "S":
        cur[0] += distance*dx[1]
        cur[1] += distance*dy[1]
    elif direction == "E":
        cur[0] += distance*dx[2]
        cur[1] += distance*dy[2]
    elif direction == "W":
        cur[0] += distance*dx[3]
        cur[1] += distance*dy[3]

print(cur[0], cur[1])