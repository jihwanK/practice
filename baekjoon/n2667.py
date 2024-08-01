import sys


def solution(N, gg):
    answer = []
    N = int(N)

    graph = []
    visited = [[0] * N for _ in range(N)]

    for g in gg.split('\n'):
        graph.append(list(map(int, list(g))))

    def dfs(graph, cur, identifier, num):
        r, c = cur[0], cur[1]
        visited[r][c] = identifier

        if 0 <= r + 1 < len(graph) and graph[r+1][c] == 1 and visited[r+1][c] == 0:
            num = dfs(graph, (r+1, c), identifier, num+1)
        if 0 <= r - 1 < len(graph) and graph[r-1][c] == 1 and visited[r-1][c] == 0:
            num = dfs(graph, (r-1, c), identifier, num+1)
        if 0 <= c + 1 < len(graph) and graph[r][c+1] == 1 and visited[r][c+1] == 0:
            num = dfs(graph, (r, c+1), identifier, num+1)
        if 0 <= c - 1 < len(graph) and graph[r][c-1] == 1 and visited[r][c-1] == 0:
            num = dfs(graph, (r, c-1), identifier, num+1)

        return num

    identifier = 1
    for r in range(N):
        for c in range(N):
            if graph[r][c] == 1 and visited[r][c] == 0:
                ans = dfs(graph, (r, c), identifier, 1)
                identifier += 1
                answer.append(ans)

    print(len(answer))
    for ans in answer:
        print(ans)


gg = '''0110100
0110101
1110101
0000111
0100000
0111110
0111000'''
solution("7", gg)
