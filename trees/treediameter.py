import sys
sys.setrecursionlimit(20000006)

N = int(input())
edges = [[] for _ in range(N + 1)]
for _ in range(N - 1):
  a, b = map(int, input().split())
  edges[a].append(b)
  edges[b].append(a)

d = [0]
r = [0]
def dfs(root, parent, depth):
  for i in edges[root]:
    if i != parent:
      dfs(i, root, depth + 1)
  
  if depth > d[0]:
    d[0] = depth
    r[0] = root 

dfs(1, 0, 0)
dfs(r[0], 0, 0)
print(d[0])