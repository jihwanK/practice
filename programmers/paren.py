from collections import deque


def split(paren):
    if not paren: return paren, paren
    op, cp = 0, 0
    for i, ch in enumerate(paren):
        if ch == '(':
            op += 1
        else:
            cp += 1
        if op == cp:
            return paren[:i+1], paren[i+1:]


def check(paren):
    if not paren: return True
    stack = deque()
    for ch in paren:
        if ch == '(':
            stack.append(ch)
        else:
            try:
                stack.pop()
            except Exception as e:
                return False
    return True

def convert(paren):
    res = []
    for ch in paren:
        if ch == '(':
            res.append(')')
        else:
            res.append('(')
    return res


def dfs(paren):
    if check(paren): return paren
    u, v = split(paren)
    res_u, res_v = check(u), check(v)
    # print(f'paren: {paren}, u: {u}-{res_u}, v: {v}-{res_v}')

    if res_u and res_v:
        return u + v
    elif res_v == False:
        return u + dfs(v)
    else:
        if len(u) > 2:
            return ['('] + dfs(v) + [')'] + convert(u[1:-1])
        elif len(u) == 2:
            return ['('] + dfs(v) + [')']
        else:
            return dfs(v)


def solution(paren):
    if not paren:
        return paren

    return ''.join(dfs(list(paren)))
    



solution("()))((()")
# solution("()")
