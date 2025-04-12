K, N = map(int, input().split())

# Please write your code here.
numbers = []
answer = 0
def choose(cnt):
    global answer
    global numbers

    if cnt == N:
        answer += 1
        print(*numbers)
        return
    
    for k in range(1, K+1):
        if len(numbers) < 2 or (len(numbers) >= 2 and numbers[-2] != numbers[-1]) \
        or (len(numbers) >= 2 and numbers[-1] != k):
            numbers.append(k)
            choose(cnt+1)
            numbers.pop()

choose(0)
# print(answer)