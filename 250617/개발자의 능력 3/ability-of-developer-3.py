abilities = list(map(int, input().split()))

# Please write your code here.
answer = 1e10
for i in range(6):
    for j in range(i+1, 6):
        for k in range(j+1, 6):
            p_sum = abilities[i] + abilities[j] + abilities[k]
            answer = min(answer, abs(2*p_sum-sum(abilities)))
print(answer)