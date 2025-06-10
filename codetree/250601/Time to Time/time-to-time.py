a, b, c, d = map(int, input().split())

# Please write your code here.
result = (c-a)*60

if d - b < 0:
    result -= 60
    result += (60+d-b)
else:
    result += (d-b)

print(result)
