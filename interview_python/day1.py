# import numpy as np


def argmin(L, idx):
    ans = 987_654_321
    ans_i = 0
    for i in range(idx, len(L)):
        if L[i] < ans:
            ans = L[i]
            ans_i = i
    return ans_i


def reverse(L):
    return L[::-1]


def reversort(L):
    global total_cost
    for i in range(0, len(L)-1):
        j = argmin(L, i)
        new_L = reverse(L[i:j+1])
        L = L[:i] + new_L + L[j+1:]
        # print(L)

        total_cost += (j - i + 1)
        # print(i, j, j - i + 1, total_cost)


global total_cost

N = int(input())
for t_n in range(N):
    input()

    total_cost = 0
    L = list(map(int, input().split()))
    reversort(L)

    print(f"Case #{(t_n + 1)}: {total_cost}")
