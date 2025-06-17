N = int(input())
a1, b1, c1 = map(int, input().split())
a2, b2, c2 = map(int, input().split())

# Please write your code here.
for i in range(1, N+1):
    for j in range(1, N+1):
        for k in range(1, N+1):
            if (abs(i-a1) <= 2 and abs(j-b1) <= 2 and abs(k-c1)) or \
                (abs(i-a2) <= 2 and abs(j-b2) <= 2 and abs(k-c2)):
                answer += 1