n = int(input())

# Please write your code here.
answer = []

while n > 1:
    answer.append(n%2)
    n //= 2
answer.append(n)

if n == 0:
    print(''.join(map(str, answer[::-1][1:])))
else:
    print(''.join(map(str, answer[::-1])))