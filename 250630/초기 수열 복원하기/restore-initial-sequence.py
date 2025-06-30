n = int(input())
adjacent = list(map(int, input().split()))

# Please write your code here.
is_successful = False
for first in range(1, n+1):
    answer = [0]*n
    answer[0] = first
    for i in range(n-1):
        next_val = adjacent[i] - answer[i]
        if next_val not in answer:
            answer[i+1] = next_val
            is_successful = True
        else:
            is_successful = False
            break
    if is_successful:
        break

print(*answer)