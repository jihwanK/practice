MAX_N = 5

codenames = []
scores = []
for _ in range(MAX_N):
    codename, score = input().split()
    codenames.append(codename)
    scores.append(int(score))

# Please write your code here.
class Agent:
    def __init__(self, codename, score):
        self.codename = codename
        self.score = score
    
    def print_elements(self):
        print(f"{self.codename} {self.score}")

agents = [0] * MAX_N
for i in range(MAX_N):
    agents[i] = (Agent(codenames[i], scores[i]))
    
worst_score = 1000
worst_agent = 0
for agent in agents: 
    if agent.score < worst_score:
        worst_score = agent.score
        worst_agent = agent

worst_agent.print_elements()
    

