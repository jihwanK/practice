m1, d1, m2, d2 = map(int, input().split())

# Please write your code here.
days = [0,31,28,31,30,31,30,31,31,30,31,30,31]

day1 = 0
for m in range(1, m1):
    day1 += days[m]
day1 += d1

day2 = 0
for m in range(1, m2):
    day2 += days[m]
day2 += d2

print(day2-day1+1)