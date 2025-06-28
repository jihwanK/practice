n = int(input())
l = []
r = []
for _ in range(n):
    left, right = map(int, input().split())
    l.append(left)
    r.append(right)

# Please write your code here.
candidates = []
for i in range(n):
    for j in range(i+1, n):
        for k in range(j+1, n):
            candidates.append((i, j, k))

flag = False
answer = 0
for i, j, k in candidates:
    for n1 in range(n):
        if flag: break
        for n2 in range(n1+1, n):
            if flag: break
            if n1 != i and n1 != j and n1 != k and n2 != i and n2 != j and n2 != k:
                if l[n1] <= l[n2] <= r[n1] or l[n2] <= l[n1] <= r[n2]:
                    flag = True
    if not flag:
        answer += 1
    else: flag = False
print(answer)