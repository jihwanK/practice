def solution(m, n, puddles):
    answer = []
    for y in range(n):
        tmp = []
        for x in range(m):
            print(answer)
            print(tmp)
            print(x, y)
            if x == 0 or y == 0:
                tmp.append(1)
            elif [x+1, y+1] in puddles:
                tmp.append(0)
            else:
                tmp.append(sum([answer[y-1][x], tmp[x-1]]))
        answer.append(tmp)
    return answer[-1][-1]
    
solution(4, 3, [[2,2]])