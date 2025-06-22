n = int(input())
a, b, c = [], [], []
for _ in range(n):
    num, cnt1, cnt2 = map(int, input().split())
    a.append(num)
    b.append(cnt1)
    c.append(cnt2)

# Please write your code here.
def do_match(num_a, num_b):
    count_1, count_2 = 0, 0
    for n_a, n_b in zip(str(num_a), str(num_b)):
        if n_a == n_b:
            count_1 += 1
        elif n_b in str(num_a):
            count_2 += 1
    return count_1, count_2

answer = 0
for i in range(1, 10):
    for j in range(1, 10):
        if i == j: continue
        for k in range(1, 10):
            if i == k or j == k: continue
            num_a = int(''.join([str(i), str(j), str(k)]))

            sub_answer = 0
            for num_b, cnt1, cnt2 in zip(a, b, c):
                sub_answer += (do_match(num_a, num_b) == (cnt1, cnt2))
            if sub_answer == n:
                answer += 1

print(answer)