from collections import defaultdict
import sys

def solution(vertices, edges):
    sys.setrecursionlimit(10**8)

    N, M, R = map(int, vertices.split())

    graph = defaultdict(list)
    visited = [0 for _ in range(N+1)]

    for edge in edges:
        s, d = map(int, edge.split())
        graph[s].append(d)
        graph[d].append(s)

    idx = 1
    def dfs(graph, cur):
        nonlocal idx
        visited[cur] = idx
        idx += 1
        
        for dest in sorted(graph[cur]):
            if visited[dest] == 0:
                dfs(graph, dest)

    dfs(graph, R)

    for ans in visited[1:]:
        print(ans)


solution("5 5 1", ["1 4", "1 2", "2 3", "2 4", "3 4"])