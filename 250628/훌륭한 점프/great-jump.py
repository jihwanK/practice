n, k = map(int, input().split())
arr = list(map(int, input().split()))

# Please write your code here.
i = 0
visited = []
while i < n:
    visited.append(min(arr[i:i+k]))
    i += 1
print(max(visited))