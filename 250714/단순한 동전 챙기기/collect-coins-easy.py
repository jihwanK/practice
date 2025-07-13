n = int(input())
grid = [list(input()) for _ in range(n)]

# Please write your code here.
coins = {}
start, end = None, None
for r in range(n):
    for c in range(n):
        if grid[r][c] not in ".ES":
            coins[grid[r][c]] = (r, c)
        elif grid[r][c] == "E":
            end = (r, c)
        elif grid[r][c] == "S":
            start = (r, c)
            
# coins = {grid[r][c]: (r, c) for r in range(n) for c in range(n) if grid[r][c] not in ".ES"}

answer = 1e10
trace = []
def recur(cnt):
    global answer

    if cnt == 3:
        # print(trace)
        subans = abs(start[0]-coins[trace[0]][0]) + abs(start[1]-coins[trace[0]][1])
        for prev, cur in zip(trace, trace[1:]):
            subans += abs(coins[prev][0]-coins[cur][0]) + abs(coins[prev][1]-coins[cur][1])
        subans += abs(coins[trace[-1]][0]-end[0]) + abs(coins[trace[-1]][1]-end[1])
        answer = min(answer, subans)
    
    for coin in sorted(coins.keys()):
        if len(trace) == 0 or trace[-1] < coin:
            trace.append(coin)
            recur(cnt+1)
            trace.pop()

recur(0)
if answer == 1e10:
    print(-1)
else:
    print(answer)