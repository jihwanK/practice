n = int(input())
A = list(map(int, input().split()))

# Please write your code here.
dist = 987654321
for home in range(1, n+1):
    dist_i = 0
    for idx, a in enumerate(A, 1):
        dist_i += a*(abs(idx-home))
    if dist > dist_i:
        dist = dist_i
print(dist)