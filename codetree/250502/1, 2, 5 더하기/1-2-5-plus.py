n = int(input())

# Please write your code here.
dp = [0]*(n+1)
numbers = [1,2,5]

for i in range(3):
    dp[numbers[i]] = 1

for i in range(n+1):
    for j in range(3):
            if (i-numbers[j]) >= 0:
                dp[i] = dp[i] + dp[i-numbers[j]]

print(dp[n]%10007)