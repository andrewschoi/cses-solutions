n = int(input())
ans = [1000001] * (n + 1)
ans[0] = 0

for i in range(1, len(ans)):
  for digit in str(i):
    if i - int(digit) >= 0:
      ans[i] = min(ans[i], 1 + ans[i - int(digit)])

print(ans[-1])