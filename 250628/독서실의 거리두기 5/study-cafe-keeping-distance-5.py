N = int(input())
seat = list(input())

# Please write your code here.
answer = 0
for new in range(N):
    min_dist = 1e10
    if seat[new] == '1': continue
    seat[new] = '1'

    i = 0
    j = 1
    while i < N:
        if j >= N: break
        if seat[i] == '0': continue
        if seat[j] == '0':
            j += 1
        else:
            min_dist = min(min_dist, j-i)
            i = j
            j = i + 1
    answer = max(answer, min_dist)
    seat[new] = '0'

print(answer)
