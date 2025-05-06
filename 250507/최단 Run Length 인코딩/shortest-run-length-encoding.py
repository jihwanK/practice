A = input()

# Please write your code here.
answer = []

start, end = 0, len(A)-1
while A[start] == A[end] and end >= 0 and start != end:
    end -= 1
if end != len(A)-1:
    A = A[end+1:] + A[:end+1]
# print(A)

start, end = 0, 0
while True:
    if end == len(A):
        answer.append(A[start])
        answer.append(str(end-start))
        break
    elif A[start] == A[end]:
        end += 1
    else:
        answer.append(A[start])
        answer.append(str(end-start))
        start = end

print(len(''.join(answer)))
