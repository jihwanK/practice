N, K = map(int, input().split())
arr = [int(input()) for _ in range(N)]

# Please write your code here.
arr.sort()
flag = False
for n in range(N, 0, -1):
    for i in range(N-n+1):
        tmp = arr[i:i+n]
        if tmp[-1] - tmp[0] <= K:
            flag = True
            print(n)
            break
    if flag:
        break