N, M = map(int, input().split())

# Process A's movements
v = []
t = []
for _ in range(N):
    vi, ti = map(int, input().split())
    v.append(vi)
    t.append(ti)

# Process B's movements
v2 = []
t2 = []
for _ in range(M):
    vi, ti = map(int, input().split())
    v2.append(vi)
    t2.append(ti)

# Please write your code here.
position_a = [0]*1_000_001
position_b = [0]*1_000_001

answer = 0
fameofhonour = None

cur = 1
for i in range(N):
    for delta in range(t[i]):
        position_a[cur] = position_a[cur-1] + v[i]
        cur += 1

cur = 1
for i in range(M):
    for delta in range(t2[i]):
        position_b[cur] = position_b[cur-1] + v2[i]
        cur += 1

for a, b in zip(position_a[1:cur], position_b[1:cur]):
    if a > b:
        if fameofhonour != "a":
            answer += 1
        fameofhonour = "a"
    elif a < b:
        if fameofhonour != "b":
            answer += 1
        fameofhonour = "b"
    else:
        if fameofhonour != "ab" and a != 0 and b != 0:
            answer += 1
        fameofhonour = "ab"

print(answer)
