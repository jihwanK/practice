n, m = map(int, input().split())

d = []
t = []
for _ in range(n):
    direction, time = input().split()
    d.append(direction)
    t.append(int(time))

d2 = []
t2 = []
for _ in range(m):
    direction, time = input().split()
    d2.append(direction)
    t2.append(int(time))

# Please write your code here.
pos_a, pos_b = [1e7]*1_000_000, [1e7]*1_000_000
cur = 0
t_a = 0
for i in range(n):
    for _ in range(t[i]):
        if d[i] == "R":
            cur += 1
        else:
            cur -= 1
        pos_a[t_a] = cur
        t_a += 1

cur = 0
t_b = 0
for i in range(m):
    for _ in range(t2[i]):
        if d2[i] == "R":
            cur += 1
        else:
            cur -= 1
        pos_b[t_b] = cur
        t_b += 1

answer = -1
for i in range(1_000_000):
    if pos_a[i] == pos_b[i] and pos_a[i] != 1e7:
        answer = i
        break

print(answer)
