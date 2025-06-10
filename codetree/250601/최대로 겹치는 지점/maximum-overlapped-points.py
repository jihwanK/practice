n = int(input())
segments = [tuple(map(int, input().split())) for _ in range(n)]

# Please write your code here.
axis = [0]*101

for segment_a, segment_b in segments:
    for i in range(segment_a, segment_b+1):
        axis[i] += 1

print(max(axis))