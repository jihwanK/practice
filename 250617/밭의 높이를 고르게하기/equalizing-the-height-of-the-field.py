N, H, T = map(int, input().split())
arr = list(map(int, input().split()))

# Please write your code here.
answer = 1e10
for i in range(N-T+1):
    cnt = 0
    for j in range(i, i+T):
        if arr[j] != H:
            cnt += abs(H - arr[j])
    answer = min(answer, cnt)
print(answer)