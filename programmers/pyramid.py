def solution(n):
    size = n * (n+1) // 2
    answer = [[-1]*(i+1) for i in range(n)]
    
    i, j = -1, 0
    turning_point = n
    direction = 0
    cur = 0
    for k in range(1, size+1):
        # print((i, j), k, answer, direction)
        if direction == 0:
            i += 1
        elif direction == 1:
            j += 1
        elif direction == 2:
            i -= 1
            j -= 1
        
        answer[i][j] = k
        cur += 1
        
        if cur % turning_point == 0:
            direction = (direction+1) % 3
            turning_point -= 1
            cur = 0
            
    return answer

answer = solution(5)
print([ele for row in answer for ele in row ])