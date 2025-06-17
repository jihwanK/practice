N, K = map(int, input().split())
# candy = []
pos = []
candy = [0]*101
for _ in range(N):
    c, p = map(int, input().split())
    # candy.append(c)
    candy[p] = c
    pos.append(p)

# Please write your code here.
answer = 0
for c in range(K, max(pos)-K):
    answer = max(answer, sum(candy[c-K:c+K+1]))
print(answer)