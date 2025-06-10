N = int(input())
arr = [int(input()) for _ in range(N)]

# Please write your code here.
def sign(num):
    if num > 0:
        return 1
    else:
        return -1

cnt = 1
ans = 1
for i in range(1, N):
    if sign(arr[i-1]) != sign(arr[i]):
        ans = max(ans, cnt)
        cnt = 1
    else:
        cnt += 1

ans = max(ans, cnt)
print(ans)