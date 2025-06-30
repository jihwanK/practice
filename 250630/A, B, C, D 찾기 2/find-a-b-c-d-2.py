nums = list(map(int, input().split()))

# Please write your code here.
nums.sort()
a = nums[0]
b = nums[1]
candidates = [0]*15
for c in range(b, 41):
    for d in range(c, 41):
        if a+b+c+d != nums[-1]: continue
        candidates[0] = a
        candidates[1] = b
        candidates[2] = c
        candidates[3] = d
        candidates[4] = a + b
        candidates[5] = b + c
        candidates[6] = c + d
        candidates[7] = d + a
        candidates[8] = a + c
        candidates[9] = b + d
        candidates[10] = a + b + c
        candidates[11] = a + b + d
        candidates[12] = a + c + d
        candidates[13] = b + c + d
        candidates[14] = a + b + c + d
        if nums == sorted(candidates):
            print(a, b, c, d)