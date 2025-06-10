n = int(input())

# Please write your code here.
if n == 0:
    print(0)
elif n == 1:
    print(1)
else:    
    answer = []

    while n > 1:
        answer.append(n%2)
        n //= 2
    answer.append(n)

    if n == 0:
        print(''.join(map(str, answer[::-1][1:])))
    else:
        print(''.join(map(str, answer[::-1])))