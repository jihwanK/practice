n, k = map(int, input().split())
arr = list(map(int, input().split()))

# Please write your code here.
i = 0
answer = arr[0]
while i < n:
    possible_i = i
    possible_v = 1e10
    for j in range(possible_i+1, possible_i+k+1):
        # print(possible_i, j, possible_v, i, answer)
        if j < n and arr[j] < possible_v:
            i = j
            possible_v = arr[j]
    if i == possible_i:
        break
    answer = max(answer, possible_v)
print(answer)