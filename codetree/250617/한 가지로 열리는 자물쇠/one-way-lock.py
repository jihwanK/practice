N = int(input())
a, b, c = map(int, input().split())

# Please write your code here.
# answer = 0
# for i in range(1, N+1):
#     for j in range(1, N+1):
#         for k in range(1, N+1):
#             if (abs(i-a) <= 2) or (abs(j-b) <= 2) or (abs(k-c) <= 2):
#                 answer += 1
# print(answer)

i = len(range(max(1, a-2), min(N, a+2)+1))
j = len(range(max(1, b-2), min(N, b+2)+1))
k = len(range(max(1, c-2), min(N, c+2)+1))
print((i+j+k)*N*N - i*j*N - j*k*N - k*i*N + i*j*k)