n = int(input())
lines = []
for _ in range(n):
    a, b = map(int, input().split())
    lines.append((a, b))

# 선분을 끝점 기준으로 정렬 (이렇게 하면 DP 계산이 더 간단해집니다)
lines.sort(key=lambda x: x[1])

dp = [1] * n  # 각 선분을 최소 1개는 선택할 수 있음

for i in range(1, n):
    for j in range(i):
        # j번째 선분의 끝점이 i번째 선분의 시작점보다 작거나 같으면 겹치지 않음
        if lines[j][1] <= lines[i][0]:
            dp[i] = max(dp[i], dp[j] + 1)

print(max(dp))