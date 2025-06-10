n = int(input())
nums = list(map(int, input().split()))

# Please write your code here.
for num in sorted(nums):
    print(num, end=' ')
print()
for num in sorted(nums, reverse=True):
    print(num, end=' ')