def solution(k, room_numbers):
    answer = []
    rooms = [-1] * (k+1)
    
    def assign_room(client, cur):     
        print(client, cur, answer)        
        
        if rooms[cur] == -1:
            rooms[cur] = 1
            answer.append(cur)
            if len(answer) == len(room_numbers):
                return
            return assign_room(client+1, room_numbers[client+1])
        else:
            return assign_room(client, cur+1)
        
    assign_room(0, room_numbers[0])
    
    return answer

solution(10, [1,3,4,1,3,1])