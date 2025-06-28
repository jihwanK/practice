N = int(input())
seat = list(input())

# Please write your code here.
answer = 0
for new in range(N):
    min_dist = 1e10
    if seat[new] == '1': continue
    seat[new] = '1'

    # print(seat)
    i = 0
    j = 1
    while i < N:
        if j >= N: break
        # print(min_dist, i, j, new, seat[i], seat[j], seat[new])
        if seat[i] == '0': 
            i += 1
            j = i + 1
            continue
        if seat[j] == '0':
            j += 1
        else:
            min_dist = min(min_dist, j-i)
            i = j
            j = i + 1
    answer = max(answer, min_dist)
    seat[new] = '0'

print(answer)
