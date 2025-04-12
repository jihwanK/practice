n = int(input())

# Please write your code here.
answer = []
visited = [False] * (n+1)

def choose(cnt):
    if cnt == n:
        print(*answer)
        return

    for i in range(n, 0, -1):
        if visited[i]:
            continue
        
        visited[i] = True
        answer.append(i)
        choose(cnt+1)
        answer.pop()
        visited[i] = False

choose(0)