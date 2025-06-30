nums = list(map(int, input().split()))

# Please write your code here.
nums.sort()
a = nums[0]
for b in range(a, 41):
    for c in range(b, 41):
        for d in range(c, 41):
            if a+b+c+d != nums[-1] \
                or b+c+d != nums[-2] \
                or a+c+d != nums[-3] \
                or a+b+d != nums[-4]: continue
            print(a,b,c,d)