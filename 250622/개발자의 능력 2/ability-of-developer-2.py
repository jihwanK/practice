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
                for e in range(6):
                    if e == a or e == b or e == c or e == d: continue
                    for f in range(6):
                        if f == a or f == b or f == c or f == d or f == e: continue
                        groups = [
                            sum([ability[a], ability[b]]),
                            sum([ability[c], ability[d]]),
                            sum([ability[e], ability[f]]),
                        ]
                        answer = min(answer, abs(max(groups)-min(groups)))

print(answer)