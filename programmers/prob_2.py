def solution(dirs):
    history = set()

    prev = {
        "x_pos": 0,
        "y_pos": 0,
    }

    cur = {
        "x_pos": 0,
        "y_pos": 0,
    }

    if (len(dirs) > 500) or (len(dirs) < 0):
        return 0
    
    for dir in dirs:
        prev["x_pos"] = cur["x_pos"]
        prev["y_pos"] = cur["y_pos"]

        if (dir != "U") and (dir != "D") and (dir != "R") and (dir != "L"):
            return 0
        elif dir == "U" and check_boundary(cur, dir):
            cur["y_pos"] += 1
        elif dir == "D" and check_boundary(cur, dir):
            cur["y_pos"] -= 1
        elif dir == "R" and check_boundary(cur, dir):
            cur["x_pos"] += 1
        elif dir == "L" and check_boundary(cur, dir):
            cur["x_pos"] -= 1

        prev_tup = (prev["x_pos"], prev["y_pos"])
        cur_tup = (cur["x_pos"], cur["y_pos"])
        ele_tup = (prev_tup, cur_tup)

        if not has_element(history, ele_tup) and (ele_tup[0] != ele_tup[1]):
            history.add(ele_tup)
        
    answer = len(history)
    # print("({x_pos}, {y_pos})".format(x_pos=cur["x_pos"], y_pos=cur["y_pos"]))
    
    return answer


def has_element(history, element):
    return element in history


def check_boundary(cur, dir):
    x = 0
    y = 0
    
    if dir == "U":
        y = 1
    elif dir == "D":
        y = -1
    elif dir == "R":
        x = 1
    elif dir == "L":
        x = -1
    
    if (-5 <= (cur["x_pos"] + x) <= 5) and (-5 <= (cur["y_pos"] + y) <= 5):
        return True
    else:
        return False

print(solution("ULURRDLLU"))
print(solution("LULLLLLLU"))