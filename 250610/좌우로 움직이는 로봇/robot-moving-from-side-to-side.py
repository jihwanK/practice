n, m = map(int, input().split())

# Process robot A's movements
t = []
d = []
for _ in range(n):
    time, direction = input().split()
    t.append(int(time))
    d.append(direction)

# Process robot B's movements
t_b = []
d_b = []
for _ in range(m):
    time, direction = input().split()
    t_b.append(int(time))
    d_b.append(direction)

# Please write your code here.
position_a = [1e10]*1_000_001
position_b = [1e10]*1_000_001
position_a[0] = 0
position_b[0] = 0

time_a = 0
for i in range(n):
    for _ in range(t[i]):
        time_a += 1
        if d[i] == "L":
            position_a[time_a] = position_a[time_a-1] - 1
        else:
            position_a[time_a] = position_a[time_a-1] + 1

time_b = 0
for i in range(m):
    for _ in range(t_b[i]):
        time_b += 1
        if d_b[i] == "L":
            position_b[time_b] = position_b[time_b-1] - 1
        else:
            position_b[time_b] = position_b[time_b-1] + 1

time = max(time_a, time_b)
answer = 0
for i in range(1, time+1):
    if i > time_a:
        position_a[i] = position_a[i-1]
    elif i > time_b:
        position_b[i] = position_b[i-1]
    
    if (position_a[i-1] != position_b[i-1]) and (position_a[i] == position_b[i]):
        # print(i)
        answer += 1

print(answer)
# print(position_a[:30])
# print(position_b[:30])