n, x = map(int, input().split())
weights = list(map(int, input().split()))

weights.sort()
ans = 0
l, r = 0, len(weights) - 1

while l <= r:
  light = weights[l]
  heavy = weights[r]

  if light + heavy > x:
    ans += 1
    r -= 1
  else:
    ans += 1
    l += 1
    r -= 1

print(ans)

