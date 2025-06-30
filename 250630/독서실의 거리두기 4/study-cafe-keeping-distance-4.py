N = int(input())
seat = list(input())

# Please write your code here.
def min_dist(seat):
    dist = 1e10
    start, end = 0, 1
    while start < end and end < N:
        if seat[start] == '1':
            if seat[end] == '0':
                end += 1
            else:
                dist = min(dist, end-start)
                start = end
                end += 1
    return dist

answer = 0
for i in range(N):
    for j in range(i+1, N):
        if seat[i] == '0' and seat[j] == '0':
            seat[i] = '1'
            seat[j] = '1'
            answer = max(answer, min_dist(seat))
            seat[i] = '0'
            seat[j] = '0'
print(answer)