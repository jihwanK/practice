N, B = map(int, input().split())
P = [int(input()) for _ in range(N)]

# Please write your code here.
P.sort()
flag = False
for i in range(N):
    if sum(P[:i]) + P[i]//2 > B:
        flag = True
        break
if flag:
    print(i)
else:
    print(N)
