N, M = map(int, input().split())

# Please write your code here.
answer = []

def choose(cnt):
    if cnt == M:
        print(*answer)
        return
    
    for i in range(1, N+1):
        if i not in answer and not list(filter(lambda x: x > i, answer)):
            answer.append(i)
            choose(cnt+1)
            answer.pop()

choose(0)
# print(list(filter(lambda x: x < 2, [1,2,3])))