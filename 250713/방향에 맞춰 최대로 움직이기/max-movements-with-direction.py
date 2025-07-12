n = int(input())
num = [list(map(int, input().split())) for _ in range(n)]
move_dir = [list(map(int, input().split())) for _ in range(n)]
r, c = map(int, input().split())

# Please write your code here.
dr = [0, -1, -1, 0, 1, 1, 1, 0, -1]
dc = [0, 0, 1, 1, 1, 0, -1, -1, -1]

answer = 0
trace = []

def can_move(r, c):
    # return 1 <= r <= n and 1 <= c <= n
    return 0 <= r < n and 0 <= c < n

def recur(cur_r, cur_c):
    global answer

    if not can_move(cur_r, cur_c):
        answer = max(answer, len(trace))
        return
    
    new_r, new_c = cur_r, cur_c
    for i in range(n):
        new_r += dr[move_dir[cur_r][cur_c]]
        new_c += dc[move_dir[cur_r][cur_c]]

        # print((new_r, new_c), num[cur_r][cur_c])
        # print(trace)

        if can_move(new_r, new_c) and num[cur_r][cur_c] < num[new_r][new_c]:
            trace.append((new_r, new_c))
            recur(new_r, new_c)
            trace.pop()
        else:
            answer = max(answer, len(trace))



recur(r-1, c-1)
print(answer)


