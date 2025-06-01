m1, d1, m2, d2 = map(int, input().split())

# Please write your code here.
days = [0,31,28,31,30,31,30,31,31,30,31,30,31]
names = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]
days_diff = 0

for m in range(0, m1):
    days_diff -= days[m]
days_diff -= d1

for m in range(0, m2):
    days_diff += days[m]
days_diff += d2

print(names[(days_diff)%7])