ability = list(map(int, input().split()))

# Please write your code here.
answer = 1e10
for a in range(6):
    for b in range(6):
        if a == b: continue
        for c in range(6):
            if c == a or c == b: continue
            for d in range(6):
                if d == a or d == b or d == c: continue
                group1 = sum([ability[a], ability[b]])
                group2 = sum([ability[c], ability[d]])
                group3 = sum(ability) - group1 - group2
                groups = [group1, group2, group3]
                answer = min(answer, abs(max(groups)-min(groups)))

print(answer)