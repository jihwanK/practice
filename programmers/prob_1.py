def solution(skill, skill_trees):
    answer = 0
    
    # constrains 
    if (len(skill_trees) < 1) or (len(skill_trees) > 20):
        return 0
    
    for ele in skill_trees:
        checked_pos = 0
        possibility = True
        
        # constrains 
        if (len(ele) < 2) or (len(ele) > 26):
            continue
        
        for e in ele:
            if checked_pos == len(skill):
                break

            # if advanced skill comes earlier
            if e in skill[(checked_pos+1):]:
                possibility = False
                break
            elif e == skill[checked_pos]:
                checked_pos += 1
                
        if possibility:
            answer += 1
        
    return answer

print(solution("CBD", ["BACDE", "CBADF", "AECB", "BDA"]))