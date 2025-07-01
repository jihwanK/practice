N = int(input())
heights = [int(input()) for _ in range(N)]

# Please write your code here.
heights.sort()
highest, lowest = heights[-1], heights[0]
answer = 1e10

gap = highest - lowest
if gap <= 17:
    print(answer)
else:
    if (gap - 17) % 2 != 0:
        #1
        low_standard = lowest + (gap-17)//2
        high_standard = highest - ((gap-17)//2 + 1)
        sub = 0

        for h in heights:
            if h < low_standard:
                sub += (low_standard-h)**2
            elif h > high_standard:
                sub += (h-high_standard)**2
        answer = min(answer, sub)

        low_standard = lowest + ((gap-17)//2 + 1)
        high_standard = highest - (gap-17)//2
        sub = 0

        for h in heights:
            if h < low_standard:
                sub += (low_standard-h)**2
            elif h > high_standard:
                sub += (h-high_standard)**2
        answer = min(answer, sub)
    
    else:
        low_standard = lowest + (gap-17)//2
        high_standard = highest - (gap-17)//2
        sub = 0

        for h in heights:
            if h < low_standard:
                sub += (low_standard-h)**2
            elif h > high_standard:
                sub += (h-high_standard)**2
        answer = min(answer, sub)

print(answer)