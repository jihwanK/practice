import sys
sys.setrecursionlimit(10000000)


def check_compression(arr, lt, rb):
    check = arr[lt[1]][lt[0]]
    for x in range(lt[0], rb[0]):
        for y in range(lt[1], rb[1]):
            if arr[y][x] != check:
                return False
    return check


def solution(arr):
    answer = [0, 0]
    width, height = len(arr[0]), len(arr)

    def compress(lt, rb):
        x1, y1 = lt # left top
        x2, y2 = rb # right bottom

        if x1 == x2 and y1 == y2:
            answer[arr[y1][x1]] += 1
            return

        check = check_compression(arr, lt, rb)
        if check is not False:
            answer[check] += 1
            return

        # lt, ((x1+x2)//2, (y1+y2)//2)
        # ((x1+x2)//2, y1), (x2, (y1+y2)//2)
        # (x1, (y1+y2)//2), ((x1+x2)//2, y2)
        # ((x1+x2)//2, (y1+y2)//2), rb

        compress(lt, ((x1+x2)//2, (y1+y2)//2))
        compress(((x1+x2)//2, y1), (x2, (y1+y2)//2))
        compress((x1, (y1+y2)//2), ((x1+x2)//2, y2))
        compress(((x1+x2)//2, (y1+y2)//2), rb)

    compress((0, 0), (width, height))

    return answer

print(solution([[1,1,0,0],[1,0,0,0],[1,0,0,1],[1,1,1,1]]))
