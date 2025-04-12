n, m = map(int, input().split())
edges = [tuple(map(int, input().split())) for _ in range(m)]

# Please write your code here.
from collections import defaultdict

graph = defaultdict(list)
for u, v in edges:
    graph[u].append(v)
    graph[v].append(u)

answer = 0
visited = [False]*(n+1)
def dfs(v):
    global answer

    for u in graph[v]:
        if visited[u]:
            continue
        visited[u] = True
        answer += 1
        dfs(u)

visited[1] = True
dfs(1)
print(answer)