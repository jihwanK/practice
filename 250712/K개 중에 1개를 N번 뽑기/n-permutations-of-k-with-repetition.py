K, N = map(int, input().split())

# Please write your code here.
answer = []

def choose(cur):
    if len(answer) == N:
        print(*answer)
        return
    
    for k in range(1, K+1):
        answer.append(k)
        choose(k)
        answer.pop()

choose(1)