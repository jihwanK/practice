# N = map(int, input().strip().split(' '))

N = int(input().strip())
possible_w = []

for w in range(1, N+1):
    if N % w == 0:
        possible_w.append(w)

size = len(possible_w)
ans = 987654321

if size % 2 == 0:
    for idx in range(0, int(size/2)):
        diff = abs(possible_w[idx] - possible_w[size-idx-1])
        if diff < ans:
            ans = diff
else:
    for idx in range(0, int((size/2) + 1)):
        diff = abs(possible_w[idx] - possible_w[size-idx-1])
        if diff < ans:
            ans = diff

print(possible_w)
print(ans)
