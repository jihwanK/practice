N = int(input())
a1, b1, c1 = map(int, input().split())
a2, b2, c2 = map(int, input().split())

# Please write your code here.
def is_adjecent(a, b):
    if abs(a-b) <= 2:
        return True
    elif a == N and b <= 2:
        return True
    elif a == N-1 and b == 1:
        return True
    elif a == 1 and b == N-1:
        return True
    elif a <= 2 and b == N:
        return True
    return False

answer = 0
for i in range(1, N+1):
    for j in range(1, N+1):
        for k in range(1, N+1):
            if (is_adjecent(i, a1) and is_adjecent(j, b1) and is_adjecent(k, c1)) or \
                (is_adjecent(i, a2) and is_adjecent(j, b2) and is_adjecent(k, c2)):
                answer += 1
print(answer)