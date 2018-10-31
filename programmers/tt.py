import random

# for i in range(0, 25):
    # print(random.randrange(1,25))

a = random.sample(range(1, 101), 100)
k = 0
for i in range(0, 10):
    for j in range(0, 10):
        print(a[k], end='\t')
        k += 1
    print(" ")


# q = 100
# for i in range(0, 10):
#     for j in range(0, 10):
#         print(q, end='\t')
#         q -= 1
#     print(" ")