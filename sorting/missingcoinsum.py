n = int(input())
coins = sorted(list(map(int, input().split())))

ans = 0
for i in range(len(coins)):
  if ans + 1 < coins[i]:
    break
  ans += coins[i]

print(ans + 1)