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
pos_a, pos_b = [0]*1_000_000, [0]*1_000_000
cur = 0
for i in range(n):
    for t_a in range(t[i]):
        if d[i] == "R":
            cur += 1
        else:
            cur -= 1
        pos_a[t_a] = cur

cur = 0
for i in range(m):
    for t_b in range(t2[i]):
        if d2[i] == "R":
            cur += 1
        else:
            cur -= 1
        pos_b[t_b] = cur

for i in range(1_000_000):
    if pos_a[i] == pos_b[i]:
        print(i)
        break
    