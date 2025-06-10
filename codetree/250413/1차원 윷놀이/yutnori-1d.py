n, m, k = map(int, input().split())
nums = list(map(int, input().split()))

# Please write your code here.
max_value = 0
marks = []


def count_score():
    score = 0
    positions = {mark: 1 for mark in range(k)}

    for mark, move in marks:
        positions[mark] += move

    for mark, position in positions.items():
        if position >= m:
            score += 1
    return score

def forward(cnt):
    global max_value
    global marks

    if cnt == n:
        # print(marks)
        max_value = max(max_value, count_score())
        return
    
    for i in range(k):
        marks.append((i, nums[cnt]))
        forward(cnt+1)
        marks.pop()


forward(0)
print(max_value)