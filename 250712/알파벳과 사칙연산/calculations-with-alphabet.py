expression = list(input())

# Please write your code here.
answer = -1e10
valid_alpha = list(set(expression)-set(["+", "-", "*"]))
n = len(valid_alpha)
alpha = []

def calc():
    tmp = {}
    for key, val in zip(valid_alpha, alpha):
        tmp[key] = val

    subans = 0
    symb = -1
    for exp in expression:
        if exp in valid_alpha:
            if subans == 0 and symb == -1:
                subans = tmp[exp]
            else:
                if symb == "*":
                    subans *= tmp[exp]
                    symb = -1
                elif symb == "+":
                    subans += tmp[exp]
                    symb = -1
                elif symb == "-":
                    subans -= tmp[exp]
                    symb = -1
        else:
            symb = exp
    return subans

def recur(num):
    global answer

    if num == n:
        answer = max(answer, calc())
        return

    for k in range(1, 5):
        alpha.append(k)
        recur(num+1)
        alpha.pop()

recur(0)
print(answer)