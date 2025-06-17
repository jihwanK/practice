n, k = map(int, input().split())
x = []
c = []
for _ in range(n):
    pos, char = input().split()
    x.append(int(pos))
    c.append(char)

# Please write your code here.
line = [0]*10_001
for i in range(n):
    line[x[i]] = 1 if c[i] == "G" else 2

answer = 0
max_pos = max(x)
for i in range(1, max_pos-k+1):
    answer = max(answer, sum(line[i:i+k+1]))
print(answer)