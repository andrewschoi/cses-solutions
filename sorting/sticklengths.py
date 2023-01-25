n = int(input())
sticks = list(map(int, input().split()))

sticks.sort()
median = sticks[n // 2]

ans = 0
for stick in sticks:
  ans += abs(median - stick)

print(ans)