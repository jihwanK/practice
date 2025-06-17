N, K = map(int, input().split())
candy = [0]*202
for _ in range(N):
    c, p = map(int, input().split())
    candy[p] += c

# Please write your code here.
answer = 0
if K <= 100:
    for c in range(K, 101):
        answer = max(answer, sum(candy[c-K:c+K+1]))
    print(answer)
else:
    print(sum(candy))