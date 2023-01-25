import sys
import collections
sys.setrecursionlimit(200006)

N = int(input())
edges = [[] for _ in range(N + 1)]
sub = [0] * N 
parents = [1] + list(map(int, input().split()))

for i, parent in enumerate(parents):
  edges[parent].append(i + 1)

def dfs(x):
  ans = 0
  for e in edges[x]:
    if e != parents[x - 1]:
      ans += dfs(e)
  sub[x - 1] = ans
  return ans + 1

dfs(1)
for i in sub:
  print(i)
