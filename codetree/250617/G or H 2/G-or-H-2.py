n = int(input())
people = sorted([tuple(input().split()) for _ in range(n)], key=lambda x: int(x[0]))
pos = [int(p[0]) for p in people]
alpha = [p[1] for p in people]

# Please write your code here.
answer = 0
for i in range(n):
    count = {"G":0,"H":0}
    count[alpha[i]] += 1
    for j in range(i+1, n):
        count[alpha[j]] += 1
        if (count["G"] == 0 and count["H"] > 1) or \
            (count["H"] == 0 and count["G"] > 1) or \
            (count["G"] == count["H"] and count["G"] != 0):
            answer = max(answer, pos[j]-pos[i])
print(answer)