n = int(input())
m = list(map(int, input().split()))

# Please write your code here.
dp = [0]*n

dp[0] = 1
for i in range(n):
    for j in range(i+1, n):
        if m[i] <= m[j]:
            dp[j] = dp[i]
            break
        else:
            dp[j] = dp[i] + 1

print(dp[-1])