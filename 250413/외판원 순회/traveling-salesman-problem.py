n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
visited = [False]*n
min_value = 1e10
answer = []
flag = False

def tsp(cur):
    global flag
    global min_value

    if cur == 0 and len(answer) == n:
        min_value = min(min_value, sum(answer))
        return
    
    for i in range(n):
        if visited[i]:
            continue
        
        visited[i] = True
        answer.append(A[cur][i])
        tsp(i)
        answer.pop()
        visited[i] = False

tsp(0)
print(min_value)