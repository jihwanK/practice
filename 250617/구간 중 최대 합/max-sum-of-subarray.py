n, k = map(int, input().split())
arr = list(map(int, input().split()))

# Please write your code here.
answer = 0
for i in range(n-k+1):
    answer = max(answer, sum(arr[i:i+k]))
print(answer)