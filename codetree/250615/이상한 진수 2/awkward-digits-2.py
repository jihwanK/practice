a = input()

# Please write your code here.

changed = False
binary = list(a)
for i in range(len(binary)):
    if binary[i] == '0':
        binary[i] = '1'
        changed = True
        break

if not changed:
    binary[-1] = '0'

print(int(''.join(binary), 2))

