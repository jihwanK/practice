from collections import defaultdict, deque
import numpy as np


def find_well(land, oil_wells, start):
    queue = deque()
    visited = defaultdict(lambda: False)
    n, m = len(land), len(land[0])
    queue.append(start)
    well_idx = len(oil_wells)
    oil_wells[well_idx].append(start)

    while queue:
        cur = queue.popleft()
        visited[(cur[0], cur[1])] = True
        if 0 <= cur[0]+1 < n and land[cur[0]+1][cur[1]] == 1:  # down
            if not visited[cur[0]+1, cur[1]] and (cur[0]+1, cur[1]) not in queue:
                queue.append((cur[0]+1, cur[1]))
                oil_wells[well_idx].append((cur[0]+1, cur[1]))
        if 0 <= cur[0]-1 < n and land[cur[0]-1][cur[1]] == 1:  # up
            if not visited[cur[0]-1, cur[1]] and (cur[0]-1, cur[1]) not in queue:
                queue.append((cur[0]-1, cur[1]))
                oil_wells[well_idx].append((cur[0]-1, cur[1]))
        if 0 <= cur[1]+1 < m and land[cur[0]][cur[1]+1] == 1:  # right
            if not visited[cur[0], cur[1]+1] and (cur[0], cur[1]+1) not in queue:
                queue.append((cur[0], cur[1]+1))
                oil_wells[well_idx].append((cur[0], cur[1]+1))
        if 0 <= cur[1]-1 < m and land[cur[0]][cur[1]-1] == 1:  # left
            if not visited[cur[0], cur[1]-1] and (cur[0], cur[1]-1) not in queue:
                queue.append((cur[0], cur[1]-1))
                oil_wells[well_idx].append((cur[0], cur[1]-1))
    return oil_wells


def solution(land):
    answer = 0
    n, m = len(land), len(land[0])
    oil_wells = defaultdict(list)
    print(np.array(land))

    for j in range(m):
        for i in range(n):
            if land[i][j] == 1:
                if sum([True if (i, j) in oil_wells[well] else False for well in oil_wells]) == 0:
                    oil_wells = find_well(land, oil_wells, (i, j))
    print(oil_wells)
    
    for j in range(m):
        well_idx = set()
        for i in range(n):
            if land[i][j] == 1:
                for well in oil_wells:
                    if (i, j) in oil_wells[well]:
                        well_idx.add(well)
        subanswer = sum((len(oil_wells[idx]) for idx in well_idx))
        print(well_idx)
        if subanswer > answer:
            answer = subanswer

    return answer


land = [[0, 0, 0, 1, 1, 1, 0, 0], [0, 0, 0, 0, 1, 1, 0, 0], [
    1, 1, 0, 0, 0, 1, 1, 0], [1, 1, 1, 0, 0, 0, 0, 0], [1, 1, 1, 0, 0, 0, 1, 1]]
land1 = [[1, 0, 1, 0, 1, 1], [1, 0, 1, 0, 0, 0], [1, 0, 1, 0, 0, 1], [
    1, 0, 0, 1, 0, 0], [1, 0, 0, 1, 0, 1], [1, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 1]]
ans = solution(land)  # 9
print(ans)