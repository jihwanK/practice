n = int(input())
x = []
dir = []
for _ in range(n):
    xi, di = input().split()
    x.append(int(xi))
    dir.append(di)

# Please write your code here.
trace = [0] * 2001
offset = 1000

cur = offset
for i in range(n):
    if dir[i] == "R":
        for delta in range(x[i]):
            trace[cur+delta] += 1
        cur += x[i]
    elif dir[i] == "L":
        for delta in range(1, x[i]+1):
            trace[cur-delta] += 1
        cur -= x[i]

print(len(list(filter(lambda x: x>=2, trace))))

