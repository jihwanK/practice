K, N = map(int, input().split())

# Please write your code here.
answers = []
def print_perm():
    for num in answers:
        print(num, end=' ')
    print()

def perm(cnt):
    if cnt == N:
        print_perm()
        return
    
    for i in range(1, K+1):
        answers.append(i)
        perm(cnt+1)
        answers.pop()

perm(0)