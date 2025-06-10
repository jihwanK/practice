# n, m = map(int, input().split())
# A = list(map(int, input().split()))

# # Please write your code here.
# max_value = -1
# answer = []

# def choose(cnt):
#     global max_value
    
#     if cnt == m:
#         tmp = answer[0]
#         for ele in answer[1:]:
#             tmp ^= ele
#         max_value = max(max_value, tmp)
#         return
    
#     for a in A:
#         if not answer or max(answer) > a:
#             answer.append(a)
#             choose(cnt+1)
#             answer.pop()

# choose(0)
# print(max_value)

n, m = map(int, input().split())
A = list(map(int, input().split()))

# Please write your code here.
max_value = -1
answer = []

def choose(cnt, last_item):
    global max_value
    
    if cnt == m:
        tmp = answer[0]
        for ele in answer[1:]:
            tmp ^= ele
        max_value = max(max_value, tmp)
        return
    
    for i in range(last_item, len(A)):
        answer.append(A[i])
        choose(cnt+1, last_item)
        answer.pop()

choose(0, 0)
print(max_value)