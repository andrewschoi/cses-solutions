n, x = map(int, input().split())
nums = list(map(int, input().split()))

nums = [[num, i] for i, num in enumerate(nums)]
nums.sort()

l, r = 0, len(nums) - 1
while l < r:
  if nums[l][0] + nums[r][0] == x:
    print(nums[l][1] + 1, nums[r][1] + 1) if nums[l][1] < nums[r][1] else  print(nums[r][1] + 1, nums[l][1] + 1)
    break
  elif nums[l][0] + nums[r][0] > x:
    r -= 1
  else:
    l += 1
if l == r:
  print("IMPOSSIBLE")
