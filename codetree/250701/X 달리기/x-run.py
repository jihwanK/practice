X = int(input())

# Please write your code here.
max_v = X

if X <= 3:
    print(X)
else:
    answer = 1e10
    for threshold_v in range(2, max_v):
        dist_left = X - threshold_v**2
        cur_t = 2*threshold_v - 1

        if dist_left < 0:
            break

        v = threshold_v
        while dist_left > 0:
            if dist_left - v >= 0:
                dist_left -= v
                cur_t += 1
            else:
                while dist_left - v < 0: 
                    v -= 1
        answer = min(answer, cur_t)
    print(answer)