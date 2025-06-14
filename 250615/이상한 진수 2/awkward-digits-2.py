a = input()

# Please write your code here.

if a == 1:
    print(1)
else:
    binary = list(a)
    for i in range(len(binary)):
        if binary[i] == '0':
            binary[i] = '1'
            break

    print(int(''.join(binary), 2))

