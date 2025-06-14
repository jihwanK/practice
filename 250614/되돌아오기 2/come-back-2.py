commands = input()

# Please write your code here.


dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

r, c = 0, 0
direction = 0
time = 1

for command in commands:
    if command == "L":
        direction = (direction+3) % 4
    elif command == "R":
        direction = (direction+1) % 4
    else:
        r += dr[direction]
        c += dc[direction]

    if r == 0 and c == 0:
        break
    else:
        time += 1

if r != 0 or c != 0:
    print(-1)
else:
    print(time)