n, m = map(int, input().split())
A = [0] + list(map(int, input().split()))

# Please write your code here.
dp = [[False]*(m+1) for _ in range(n+1)]

dp[0][0] = True
for i in range(1, n+1):
    for j in range(1, m+1):
        if j-A[i] >= 0 and dp[i-1][j-A[i]] == True:
            dp[i][j] = True
        
        if dp[i-1][j]:
            dp[i][j] = True


if dp[n][m]:
    print("Yes")
else:
    print("No")
