N, K = map(int, input().split())
arr = [int(input()) for _ in range(N)]

# Please write your code here.
# from itertools import combinations

# flag = False
# for n in range(N, 0, -1):
#     for chosen in combinations(arr, n):
#         if max(chosen) - min(chosen) <= K:
#             print(n)
#             flag = True
#             break
#     if flag: break

arr.sort()
# print(arr)
i, j = 0, N-1
answer = 0
while i < j:
    max_val, min_val = arr[j], arr[i]
    if max_val - min_val <= K:
        answer = max(answer, j-i+1)
        # print(j, i)
        break
    i += 1

i, j = 0, N-1
while i < j:
    max_val, min_val = arr[j], arr[i]
    if max_val - min_val <= K:
        answer = max(answer, j-i+1)
        # print(j, i)
        break
    j -= 1

print(answer)