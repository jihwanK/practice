N, M, K = map(int, input().split())
student = [int(input()) for _ in range(M)]

# Please write your code here.
from collections import Counter
counter = Counter(student)

for i in range(M):
    counter[student[i]] -= 1
    if counter[student[i]] <= 0:
        break


# from collections import defaultdict

# counter = defaultdict(int)
# for i in range(M):
#     counter[student[i]] += 1
#     if counter[student[i]] >= K:
#         break

if (i == M-1) and counter[-1] > 0:
    print(-1)
else:
    print(student[i])
