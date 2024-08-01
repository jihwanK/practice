from collections import deque, defaultdict


def solution(n, s, a, b, fares):
    taxi_map = defaultdict(list)
    price = [[0]*(n+1) for _ in range(n+1)]

    for fare_i in fares:
        src, dest, fare = fare_i
        taxi_map[src].append(dest)
        price[src][dest] = fare
        taxi_map[dest].append(src)
        price[dest][src] = fare


    # dijikstra
    answer = [0, 0, 0]
    queue = deque(taxi_map[s])

    # s -> a -> b
    # s -> a
    visited = []
    cur_price = [0 for _ in range(n+1)]
    while queue:
        next = queue.popleft()
        if next in visited:
            continue

        if next == a:
            pass

        visited.append(next)
        queue.extend(queue[next])
    answer[2] += fare
    # a -> b
    visited = []
    while queue:
        next = queue.popleft()
        if next in visited:
            continue

        if next == b:
            pass

    # s -> b -> a
    # s -> b
    fare = 0
    visited = []
    while queue:
        next = queue.popleft()
        if next in visited:
            continue

        if next == b:
            pass
    answer[2] += fare
    # a -> a
    visited = []
    while queue:
        next = queue.popleft()
        if next in visited:
            continue

        if next == a:
            pass

    # s -> a // s -> b

    return min(answer)


a = solution(6, 4, 6, 2, [[4, 1, 10], [3, 5, 24], [5, 6, 2], [3, 1, 41], [
             5, 1, 24], [4, 6, 50], [2, 4, 66], [2, 3, 22], [1, 6, 25]])  # 82
b = solution(7, 3, 4, 1, [[5, 7, 9], [4, 6, 4], [
             3, 6, 1], [3, 2, 3], [2, 1, 6]])  # 14
c = solution(6, 4, 5, 6, [[2, 6, 6], [6, 3, 7], [4, 6, 7], [6, 5, 11], [
             2, 5, 12], [5, 3, 20], [2, 4, 8], [4, 3, 9]])  # 18

print(a, "82")
print(b, "14")
print(c, "18")
