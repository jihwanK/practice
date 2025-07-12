K, N = map(int, input().split())

# Please write your code here.
answer = []

def recur(num):
    if num == N:
        print(*answer)
    
    for i in range(1, K+1):
        if len(answer) < 2 or \
            not (answer[-1] == answer[-2] == i):
            answer.append(i)
            recur(num+1)
            answer.pop()

recur(0)