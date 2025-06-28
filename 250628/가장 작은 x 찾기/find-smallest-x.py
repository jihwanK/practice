N = int(input())
ranges = [tuple(map(int, input().split())) for _ in range(N)]
a, b = zip(*ranges)
a, b = list(a), list(b)

# Please write your code here.
for x in range(1, 10001):
    for n in range(1, N+1):
        if x*2**n not in range(a[n-1], b[n-1]+1):
            flag = True
            break
    if flag:
        flag = False
    else:
        print(x)
        break