n = int(input())
m = list(map(int, input().split()))

# Please write your code here.
dp = [0]*n

for i in range(n):
    dp[i] = 1

    for j in range(i):
        if m[j] > m[i]:
            dp[i] = max(dp[i], dp[j]+1)

print(max(dp))