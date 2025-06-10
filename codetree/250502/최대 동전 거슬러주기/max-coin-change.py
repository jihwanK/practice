N, M = map(int, input().split())
coins = list(map(int, input().split()))

# Please write your code here.
dp = [-1]*(M+1)

if min(coins) > M:
    print(-1)
else:    
    for coin in coins:
        if coin <= M:
            dp[coin] = 1

    for i in range(1, M+1):
        for coin in coins:
            if i - coin >= 0:
                if dp[i-coin] == -1:
                    continue 
                    
                dp[i] = max(dp[i-coin]+1, dp[i])

    print(dp[M])