def sol_1(answer):
    res = 0
    for i in range(0, len(answer)):
        if answer[i] == ((i % 5) + 1):
            res += 1
    
    return res

def sol_2(answer):
    res = 0
    ans = []

    for i in range(0, len(answer)):
        if i % 2 == 0:
            ans.append(2)
        elif (i - 1) % 8 == 0:
            ans.append(1)
        elif (i - 3) % 8 == 0:
            ans.append(3)
        elif (i - 5) % 8 == 0:
            ans.append(4)
        elif (i - 7) % 8 == 0:
            ans.append(5)

    for i in range(0, len(answer)):
        if answer[i] == ans[i]:
            res += 1
    
    return res


def sol_3(answer):
    ans = []
    res = 0

    for i in range(0, len(answer)):
        if ((i % 10) == 0) or ((i % 10) == 1):
            ans.append(3)
        elif ((i % 10) == 2) or ((i % 10) == 3):
            ans.append(1)
        elif ((i % 10) == 4) or ((i % 10) == 5):
            ans.append(2)
        elif ((i % 10) == 6) or ((i % 10) == 7):
            ans.append(4)
        elif ((i % 10) == 8) or ((i % 10) == 9):
            ans.append(5)
    
    for i in range(0, len(answer)):
        if answer[i] == ans[i]:
            res += 1
    
    return res

def solution(answers):
    ans = []
    res = []

    ans.append(sol_1(answers))
    ans.append(sol_2(answers))
    ans.append(sol_3(answers))
    
    best = max(ans)

    for i in range(0, 3):
        if best == ans[i]:
            res.append(i+1)

    return res
