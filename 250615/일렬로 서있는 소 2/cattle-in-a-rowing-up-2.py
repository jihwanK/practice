N = int(input())
A = list(map(int, input().split()))

# Please write your code here.
cnt = 0
for i in range(len(A)):
    for j in range(i+1, len(A)):
        for k in range(j+1, len(A)):
            if A[i] <= A[j] <= A[k]:
                cnt += 1

print(cnt)