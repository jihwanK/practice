n = int(input())

# Please write your code here.
from collections import Counter

answer = 0
candidate = []

def is_beautiful():
    counter = Counter(candidate)

    for key in counter.keys():
        if counter[key] != key:
            return False
        elif counter[key] % key != 0:
            return False
    
    return True

def recur(size):
    global answer

    if size == n:
        if is_beautiful():
            answer += 1
        return

    for k in range(1, 5):
        candidate.append(k)
        recur(size+1)
        candidate.pop()

recur(0)
print(answer)
