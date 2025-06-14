a = input()

# Please write your code here.
binary = list(bin(int(a))[2:])
for i in range(len(binary)):
    if binary[i] == '0':
        binary[i] = '1'
        break

print("%s".format('0b'+''.join(binary)))

