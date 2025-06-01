n = int(input())
commands = [tuple(input().split()) for _ in range(n)]
x = []
dir = []
for num, direction in commands:
    x.append(int(num))
    dir.append(direction)

# Please write your code here.
left_end, right_end = 200_000, 0
trace = [[] for _ in range(200_001)]
offset = 100_000

cur = offset
for i in range(n):
    if dir[i] == "R":
        for delta in range(x[i]):
            trace[cur+delta].append("B")
        cur += x[i]-1
        # print(trace[offset-10:offset+10])
        if cur > right_end:
            right_end = cur
    elif dir[i] == "L":
        for delta in range(x[i]):
            trace[cur-delta].append("W")
        cur -= x[i]-1
        # print(trace[offset-10:offset+10])
        if cur < left_end:
            left_end = cur

# print(left_end, right_end, trace[offset-10:offset+10])
answer = [0, 0, 0]
for i in range(left_end, right_end+1):
    if len(trace[i]) >= 4:
        answer[2] += 1
    else:        
        if trace[i][-1] == "W":
            answer[0] += 1
        elif trace[i][-1] == "B":
            answer[1] += 1

# print(trace[left_end:right_end+1])
print(answer[0], answer[1], answer[2])