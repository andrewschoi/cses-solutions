n, x = map(int, input().split())
prices = list(map(int, input().split()))
values = list(map(int, input().split()))
ans = [[0] * (x + 1) for _ in range(n + 1)]

for i in range(1, n + 1):
  for j in range(x + 1):

    ans[i][j] = ans[i - 1][j]
    if j >= prices[i - 1]:
      ans[i][j] = max(ans[i][j], ans[i - 1][j - prices[i - 1]] + values[i - 1])

print(ans[n][x])