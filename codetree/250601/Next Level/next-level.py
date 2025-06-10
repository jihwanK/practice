user2_id, user2_level = input().split()
user2_level = int(user2_level)

# Please write your code here.
class User:
    def __init__(self, uid, ulevel):
        self.uid = uid
        self.ulevel = ulevel
    
    def print_elements(self):
        print(f"user {self.uid} lv {self.ulevel}")
    
user1 = User("codetree", 10)
user2 = User(user2_id, user2_level)

user1.print_elements()
user2.print_elements()
