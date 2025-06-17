N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

# Please write your code here.
sorted_B = sorted(B)
answer = 0
for i in range(N-M+1):
    if sorted_B == sorted(A[i:i+M]):
        answer += 1
print(answer)