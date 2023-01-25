n = int(input())
nums = list(map(int, input().split()))

ans = float("-inf")
curr = float("-inf")

for num in nums:
  curr = max(num, curr + num)
  ans = max(ans, curr)
print(ans)