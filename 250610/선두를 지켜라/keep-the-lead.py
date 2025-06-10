n, m = map(int, input().split())

# Process A's movements
v = []
t = []
for _ in range(n):
    vi, ti = map(int, input().split())
    v.append(vi)
    t.append(ti)

# Process B's movements
v2 = []
t2 = []
for _ in range(m):
    vi, ti = map(int, input().split())
    v2.append(vi)
    t2.append(ti)

# Please write your code here.
position_a = [0]*1_002
position_b = [0]*1_002

time = 0
for i in range(len(t)):
    for delta_t in range(t[i]):
        time += 1
        position_a[time] = position_a[time-1] + v[i]
# print(position_a[:20])

time = 0
for i in range(len(t2)):
    for delta_t in range(t2[i]):
        time += 1
        position_b[time] = position_b[time-1] + v2[i]
# print(position_b[:20])

answer = 0
key = None
for a, b in zip(position_a, position_b):
    if a > b and key == "b":
        answer += 1
        key = "a"
    elif a < b and key == "a":
        answer += 1
        key = "b"
    elif a > b and not key:
        key = "a"
    elif a < b and not key:
        key = "b"
print(answer)