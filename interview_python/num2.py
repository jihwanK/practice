# def check_all_case(S: str) -> list[str]:
#     set_S = set()
#
#     def recur(L: str) -> None:
#         if L.count('?') == 0:
#             set_S.add(L)
#             return
#         for ch in ['C', 'J']:
#             recur(L.replace('?', ch, 1))
#     recur(S)
#
#     return list(set_S)
#
#
# T = int(input())
#
# for test_case in range(T):
#     X, Y, S = input().split()
#     X = int(X)
#     Y = int(Y)
#     ans = 987_654_321
#
#     list_S = check_all_case(S)
#
#     for S in list_S:
#         sub_cost = 0
#
#         for idx, mural in enumerate(S):
#             if idx == len(S) - 1:
#                 break
#             if mural == 'C' and S[idx+1] == 'J':
#                 sub_cost += X
#             elif mural == 'J' and S[idx+1] == 'C':
#                 sub_cost += Y
#
#         if sub_cost < ans:
#             ans = sub_cost
#

#     print(f"Case #{test_case+1}: {ans}")

def check_S(S):
    cnt = 0
    for idx, ch in enumerate(S):
        if ch == '?' and idx == 0:
            cnt += 1
        elif ch == '?' and cnt == idx:
            cnt += 1
        elif ch != '?' and cnt == idx:
            S = S.replace('?', ch, cnt)
            # print(S, ch, cnt)
        elif ch == '?':
            S = S.replace('?', S[idx-1], 1)
            # print(S)

    # print(S)
    return S


T = int(input())

for test_case in range(T):
    X, Y, S = input().split()
    X = int(X)
    Y = int(Y)
    ans = 987_654_321

    new_S = check_S(S)
    # print(new_S)

    sub_cost = 0

    for idx, mural in enumerate(new_S):
        if idx == len(new_S) - 1:
            break
        if mural == 'C' and new_S[idx + 1] == 'J':
            sub_cost += X
        elif mural == 'J' and new_S[idx + 1] == 'C':
            sub_cost += Y

    if sub_cost < ans:
        ans = sub_cost

    print(f"Case #{test_case+1}: {ans}")
