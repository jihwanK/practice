# solution 1)
# top-down
from collections import defaultdict

def dfs(route, storage, triangle):
    cur = route[-1]
    # print(cur[0], cur[1], route)
    if len(route[:-1]) == 0:
        cur_val = triangle[cur[0]][cur[1]]
    else:
        cur_val = storage[tuple(route[:-1])] + triangle[cur[0]][cur[1]]
    storage[tuple(route)] = cur_val

    if cur[0] == (len(triangle) - 1):
        return

    # # to the left
    # l_route = route + [(cur[0]+1, cur[1])]
    # if tuple(l_route) not in storage:
    #     dfs(l_route, storage, triangle)
    # # to the right
    # r_route = route + [(cur[0]+1, cur[1]+1)]
    # if tuple(r_route) not in storage:
    #     dfs(r_route, storage, triangle)

    # to the left
    l_route = route + [(cur[0]+1, cur[1])]
    # if tuple(l_route) not in storage:
    dfs(l_route, storage, triangle)
    # to the right
    r_route = route + [(cur[0]+1, cur[1]+1)]
    # if tuple(r_route) not in storage:
    dfs(r_route, storage, triangle)

    # print(l_ans, r_ans)

    # return max(l_ans, r_ans)
    # return 0
    return


def solution(triangle):
    storage = defaultdict(lambda: 0)

    dfs([(0, 0)], storage, triangle)
    # print(len(storage))
    # print(storage)

    return max(storage.values())


print(solution([[7], [3, 8], [8, 1, 0], [2, 7, 4, 4], [4, 5, 2, 6, 5]]))