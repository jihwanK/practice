# import re
import copy
from bisect import bisect_left, bisect_right

def solution(info, querys):
    answer = []
    
    info = list(map(str.split, info))
    info = sorted(info, key=lambda x: (x[0], x[1], x[2], x[3], x[4]))
    
    querys = list(map(lambda x: x.replace(' and ', ' '), querys))
    querys = list(map(lambda x: x.split(' '), querys))
    info_n = copy.deepcopy(info)
    
    for query in querys:
        info_n = copy.deepcopy(info)
        left, right = 0, len(info)
        sub_answer = 0
        for i in range(4):
            info_n = info_n[left:right]
            info_t = list(zip(*info_n))

            if query[i] == '-':
                continue
            left = bisect_left(info_t[i], query[i])
            right = bisect_right(info_t[i], query[i])
        
        # print(left, right)
        print(query[4], info_n, info_t)
        info_n = info_n[left:right]
        info_t = list(zip(*info_n))
        # print(len(info_), info_t)
        
        for i in range(len(info_n)):
            if int(info_t[4][i]) >= int(query[4]): sub_answer += 1

        answer.append(sub_answer)
        print(answer)
        print()
    return answer

    
info = ["java backend junior pizza 150", "python frontend senior chicken 210", "python frontend senior chicken 150", "cpp backend senior pizza 260", "java backend junior chicken 80", "python backend senior chicken 50"]
query = ["java and backend and junior and pizza 100", "python and frontend and senior and chicken 200", "cpp and - and senior and pizza 250", "- and backend and senior and - 150", "- and - and - and chicken 100", "- and - and - and - 150"]
print(solution(info, query))