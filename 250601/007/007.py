secret_code, meeting_point, time = input().split()
time = int(time)

# Please write your code here.
class mission:
    def __init__(self, secret_code, meeting_point, time):
        self.secret_code = secret_code
        self.meeting_point = meeting_point
        self.time = time
    
    def print_elements(self):
        print(f"secret code : {self.secret_code}")
        print(f"meeting point : {self.meeting_point}")
        print(f"time : {self.time}")

mission = mission(secret_code, meeting_point, time)
mission.print_elements()