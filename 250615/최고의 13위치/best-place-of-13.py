n = int(input())
grid = [list(map(int, input().split())) for _ in range(n)]

# Please write your code here.
def in_range(r, c):
    return 0 <= r < n and 0 <= c < n-2

answer = 0
for r in range(n):
    for c in range(n):
        if in_range(r, c):
            answer = max(answer, sum(grid[r][c:c+3]))
print(answer)