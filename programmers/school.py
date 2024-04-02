# def solution(m, n, puddles):
#     answer = []
#     for y in range(n):
#         tmp = []
#         for x in range(m):
#             print(answer)
#             print(tmp)
#             print(x, y)
#             if x == 0 or y == 0:
#                 tmp.append(1)
#             elif [x+1, y+1] in puddles:
#                 tmp.append(0)
#             else:
#                 tmp.append(sum([answer[y-1][x], tmp[x-1]]))
#         answer.append(tmp)
#     return answer[-1][-1]


# from collections import deque

def solution(m, n, puddles):
    answer = 0
    visit = [[0]*(n+1) for _ in range(m+1)]
    puddles = [tuple(puddle) for puddle in puddles]
    path = [(1, 1)]
    all_path = set()

    def move(cur, answer, visit, path):
        visit[cur[0]][cur[1]] = 1
        if cur == (m, n):
            all_path.add(tuple(path))
            return answer + 1

        to_right = (cur[0]+1, cur[1])
        to_down = (cur[0], cur[1]+1)
        if to_right not in puddles and to_right[0] <= m and visit[to_right[0]][to_right[1]] != 1:
            path.append(to_right)
            answer = move(to_right, answer, visit, path)
            visit[to_right[0]][to_right[1]] = 0
            path.pop()
        if to_down not in puddles and to_down[1] <= n and visit[to_down[0]][to_down[1]] != 1:
            path.append(to_down)
            answer = move(to_down, answer, visit, path)
            visit[to_down[0]][to_down[1]] = 0
            path.pop()
        return answer

    answer = move((1, 1), 0, visit, path)

    return answer


if __name__ == '__main__':
    pass

solution(4, 3, [[2, 2]])
