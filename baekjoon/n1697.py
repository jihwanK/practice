import sys
from collections import deque

sys.setrecursionlimit(10**8)

answer = 987_654_321

### 176
def solution(hello):
    # cur, target = map(int, sys.stdin.readline().split())
    cur, target = map(int, hello.split())
    visited = [987654321] * 100_001
    # visited = [0] * 100_001

    queue = deque()

    queue.append(cur)
    
    while queue:
        
    

    def dfs(cur, cnt):
        global answer
        visited[cur] = min(visited[cur], cnt)
        # visited[cur] = 1

        if cur == target:
            answer = min(answer, cnt)

        print(cnt, answer)
        if 0 <= cur+1 <= 100_000 and visited[cur+1] > cnt and cnt+1 < answer:
            dfs(cur+1, cnt+1)
        if 0 <= cur-1 <= 100_000 and visited[cur-1] > cnt and cnt+1 < answer:
            dfs(cur-1, cnt+1)
        if 0 <= 2*cur <= 100_000 and visited[2*cur] > cnt and cnt+1 < answer:
            dfs(2*cur, cnt+1)

        # return answer

    dfs(cur, 0)
    print(answer)


solution("5 17")
