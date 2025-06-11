N, K, P, T = map(int, input().split())
handshakes = [tuple(map(int, input().split())) for _ in range(T)]

# Please write your code here.
handshakes.sort(key=lambda x: (x[0], x[1], x[2]))

developers = [0]*(N+1)
developers[P] = 1 # 최초 감염자

count = 0
for t, x, y in handshakes:
    if count == P:
        break

    if developers[x] or developers[y]:
        developers[x] = 1
        developers[y] = 1
        count += 1

print(''.join(map(str, developers[1:])))