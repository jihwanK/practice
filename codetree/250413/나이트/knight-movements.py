n = int(input())
r1, c1, r2, c2 = map(int, input().split())

# Please write your code here.
from collections import deque
start_pos = (r1, c1)
end_pos = (r2, c2)

visited = [[False]*n for _ in range(n)]
steps = [[1e10]*n for _ in range(n)]
steps[r1-1][c1-1] = 0

drs = [-2, -2, -1, -1, 1, 1, 2, 2]
dcs = [-1, 1, -2, 2, -2, 2, -1, 1]

def in_range(r, c):
    return 0 <= r < n and 0 <= c < n and not visited[r][c]

def bfs():
    while q:
        # print(q)
        r, c = q.popleft()

        for dr, dc in zip(drs, dcs):
            new_r, new_c = r+dr, c+dc

            if in_range(new_r, new_c):
                visited[new_r][new_c] = True
                q.append((new_r, new_c))

                if steps[new_r][new_c] > steps[r][c] + 1:
                    steps[new_r][new_c] = steps[r][c] + 1


q = deque([])
q.append((r1-1, c1-1))
visited[r1-1][c1-1] = True
bfs()
print(steps[r2-1][c2-1] if steps[r2-1][c2-1] != 1e10 else -1)