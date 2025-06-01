m1, d1, m2, d2 = map(int, input().split())
A = input()

# Please write your code here.
days = [0,31,29,31,30,31,30,31,31,30,31,30,31]
names = {"Mon": 0, "Tue": 1, "Wed": 2, "Thu": 3, "Fri": 4, "Sat": 5, "Sun": 6}

day_diff = 0
for m in range(m1):
    day_diff -= days[m]
day_diff -= d1

for m in range(m2):
    day_diff += days[m]
day_diff += d2

result = day_diff//7
if day_diff%7 >= names[A]:
    result += 1

print(result)