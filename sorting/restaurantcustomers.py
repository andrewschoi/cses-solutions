n = int(input())
intervals = [list(map(int, input().split())) for _ in range(n)]
starts = [interval[0] for interval in intervals]
ends = [interval[1] for interval in intervals]

starts.sort()
ends.sort()
i = j = 0
ans = 0
curr = 0
while i < n and j < n:
  if starts[i] <= ends[j]:
    i += 1
    curr += 1
  else:
    curr -= 1
    j += 1
  ans = max(ans, curr)

print(ans)