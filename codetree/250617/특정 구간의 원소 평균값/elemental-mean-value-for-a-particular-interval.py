n = int(input())
arr = list(map(int, input().split()))

# Please write your code here.
answer = 0
for length in range(1, n+1):
    for i in range(n-length+1):
        if sum(arr[i:i+length])/length in arr[i:i+length]:
            answer += 1
print(answer)
