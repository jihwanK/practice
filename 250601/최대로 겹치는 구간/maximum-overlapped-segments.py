n = int(input())
segments = [tuple(map(int, input().split())) for _ in range(n)]

# Please write your code here.
axis = [0]*(201)
for segment_a, segment_b in segments:
    for i in range(segment_a+100, segment_b+101):
        axis[i] += 1

max_overlapped = 0
for i in range(200):
    if axis[i] == axis[i+1]:
        if max_overlapped < axis[i]:
            max_overlapped = axis[i]

print(axis)
print(max_overlapped)