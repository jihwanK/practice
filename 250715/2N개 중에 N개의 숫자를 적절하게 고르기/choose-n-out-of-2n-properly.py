n = int(input())
num = list(map(int, input().split()))

# Please write your code here.
candidate_a = []
answer = 1e10

def recur(cnt):
    global answer

    if len(candidate_a) == n:
        answer = min(answer, abs(sum(num) - 2*sum([num[i] for i in candidate_a])))
        return

    for i in range(cnt, len(num)):
        if i not in candidate_a:
            candidate_a.append(i)
            recur(cnt+1)
            candidate_a.pop()

recur(0)
print(answer)