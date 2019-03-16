num_a = int(input().strip())
header_a = input().strip().split(' ')
row_a = []

for i in range(1, num_a):
    row_a.append(input().strip().split(' '))
row_a.sort()

############################################################


num_b = int(input().strip())
header_b = input().strip().split(' ')
header_b.remove(header_a[0])
row_b = []

for i in range(1, num_b):
    row_b.append(input().strip().split(' '))
row_b.sort()

############################################################

# print(row_a)
print(row_b)

final_row = []
tmp = []
tmp.extend(header_a)
tmp.extend(header_b)
final_row.append(tmp)

final_row.append
for i in range(0, num_a-1):
    for j in range(0, num_b-1):
        if row_a[i][0] == row_b[j][0]:
            tmp = []
            tmp.extend(row_a[i])
            tmp.append(row_b[j][1])
            tmp.append(row_b[j][2])
            final_row.append(tmp)
            break


print(' '.join(final_row[0]))
for i in range(1, num_a):
    if final_row[i][0] == str(i):
        print(' '.join(final_row[i]))
    # else:
    #     print(' '.join(row_a))