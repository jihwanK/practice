N = int(input())
moves = [tuple(input().split()) for _ in range(N)]
dir = [move[0] for move in moves]
dist = [int(move[1]) for move in moves]

# Please write your code here.
dc = {"W":-1,"S":0,"N":0,"E":1}
dr = {"N":-1,"E":0,"W":0,"S":1}

r, c = 0, 0
time = 1
stop_flag = False
for direction, distance in moves:
    if stop_flag:
        break
    for _ in range(int(distance)):
        r += dr[direction]
        c += dc[direction]

        if r == 0 and c == 0:
            print(time)
            stop_flag = True
            break
        time += 1

if r != 0 and c != 0:
    print(-1)
