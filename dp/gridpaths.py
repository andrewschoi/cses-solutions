n = int(input())
grid = [list(input()) for _ in range(n)]

ans = [[0] * len(grid[i]) for i in range(len(grid))]
ans[0][0] = 1

for i in range(len(ans)):
  for j in range(len(ans[i])):
    if grid[i][j] == "*":
      ans[i][j] = 0
      continue

    if i - 1 >= 0:
      ans[i][j] += ans[i - 1][j] % (10 ** 9 + 7)
    if j - 1>= 0:
      ans[i][j] += ans[i][j - 1] % (10 ** 9 + 7)
    

print(ans[-1][-1] % (10 ** 9 + 7))