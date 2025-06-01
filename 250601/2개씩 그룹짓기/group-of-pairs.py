n = int(input())
nums = list(map(int, input().split()))

# Please write your code here.
result = set()
nums.sort()
for i in range(len(nums)//2):
    result.add(nums[i]+nums[len(nums)-i-1])
print(max(result))