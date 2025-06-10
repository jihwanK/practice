n = int(input())
arr = list(map(int, input().split()))

# Please write your code here.
dp = [-1]*n

dp[0] = 0
for i in range(1, n):
    for j in range(i):
        if dp[j] == -1:
            continue

        if i <= j + arr[j]:
            dp[i] = max(dp[j]+1, dp[i])

print(max(dp))
        