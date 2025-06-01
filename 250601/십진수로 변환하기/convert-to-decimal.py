binary = input()

# Please write your code here.
answer = 0
for i, b in enumerate(binary[::-1]):
    answer += int(b)*(2**i)

print(answer)
