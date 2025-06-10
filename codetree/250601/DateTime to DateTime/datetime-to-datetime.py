a, b, c = map(int, input().split())

# Please write your code here.
start_time, end_time = 0, 0

end_time += a*24*60 + b*60 + c
start_time += 11*24*60 + 11*60 + 11

if end_time-start_time < 0:
    print(-1)
else:
    print(end_time-start_time)