N, K, P, T = map(int, input().split())
handshakes = [tuple(map(int, input().split())) for _ in range(T)]

# Please write your code here.
handshakes.sort(key=lambda x: (x[0], x[1], x[2]))

developers = [0]*(N+1)
transmissibility = [K]*(N+1)
developers[P] = 1 # 최초 감염자

for t, x, y in handshakes:
    if developers[x] and developers[y] and transmissibility[x] > 0 and transmissibility[y] > 0:
        transmissibility[x] -= 1
        transmissibility[y] -= 1
    elif developers[x] and transmissibility[x] > 0:
        developers[y] = 1
        transmissibility[x] -= 1
    elif developers[y] and transmissibility[y] > 0:
        developers[x] = 1
        transmissibility[y] -= 1

print(''.join(map(str, developers[1:])))