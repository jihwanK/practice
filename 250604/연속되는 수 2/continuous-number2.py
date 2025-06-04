n = int(input())
arr = [int(input()) for _ in range(n)]

# Please write your code here.
max_num = 1
cnt = 1
for i in range(1, n):
    if arr[i-1] != arr[i]:
        max_num = max(max_num, cnt)
        cnt = 1
    else:
        cnt += 1

max_num = max(max_num, cnt)
print(max_num)