n = int(input())
times = [tuple(map(int, input().split())) for _ in range(n)]
a = [t[0] for t in times]
b = [t[1] for t in times]

# Please write your code here.
answer = 0
working_hours = [0]*1001
for i in range(n):
    for worker in range(n):
        if worker != i:
            for time in range(a[worker], b[worker]):
                working_hours[time] = 1
    answer = max(answer, sum(working_hours))
    working_hours = [0]*1001
print(answer)