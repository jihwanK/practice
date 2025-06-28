N, K = map(int, input().split())
num = [int(input()) for _ in range(N)]

# Please write your code here.
answer = 0
for bomb_num in range(1, N+1):
    for i in range(N):
        for j in range(N):
            if i == j or num[i] != bomb_num: continue
            if num[i] == num[j] and j-i <= K:
                answer = max(answer, bomb_num)
print(answer)
                