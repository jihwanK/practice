N = int(input())
arr = [int(input()) for _ in range(N)]

# Please write your code here.
for i in range(1, N):
    if sign(arr[i-1]) != sign(arr[i]):
