n = int(input())
points = [tuple(map(int, input().split())) for _ in range(n)]
x = [p[0] for p in points]
y = [p[1] for p in points]

# Please write your code here.
answer = 1e10
1for i in range(n):
    new_x = x[:i]+x[i+1:]
    new_y = y[:i]+y[i+1:]

    new_min_x = min(new_x)
    new_max_x = max(new_x)
    new_min_y = min(new_y)
    new_max_y = max(new_y)

    answer = min(answer, (new_max_x-new_min_x)*(new_max_y-new_min_y))

print(answer)
