n = int(input())

# Please write your code here.
dp = [0]*10000
dp[0] = 1
dp[1] = 2
dp[2] = 7


for i in range(2, n+1):
    dp[i] = 2*dp[i-1] + 3*dp[i-2]

print(dp[n]%1000000007)