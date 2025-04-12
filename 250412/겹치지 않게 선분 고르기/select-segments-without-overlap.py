n = int(input())
x1, x2 = [], []

for _ in range(n):
    a, b = map(int, input().split())
    x1.append(a)
    x2.append(b)

# Please write your code here.
max_count = 1
lines = []

def does_intersect(l1, l2):
    if l1[0] < l2[0] and l1[1] < l2[0]:
        return False
    elif l2[0] < l1[0] and l2[1] < l1[0]:
        return False
    return True

def choose(cnt, k):
    global max_count
    global lines

    if cnt == k:
        # print(lines)
        for i in range(cnt-1):
            for j in range(i+1, cnt):
                if does_intersect(lines[i], lines[j]):
                    return
        max_count = max(max_count, len(lines))
        return

    for a, b in zip(x1, x2):
        if (a, b) not in lines:
            lines.append((a, b))
            choose(cnt+1, k)
            lines.pop()
    
    return

for i in range(1, n+1):
    choose(0, i)
print(max_count)