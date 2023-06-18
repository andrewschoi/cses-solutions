#include <bits/stdc++.h>
using namespace std;

vector<int> groups;
vector<vector<int>> adj;
bool dfs(int node, int prevGroup)
{
  if (groups[node] != 0)
    return groups[node] != prevGroup;
  groups[node] = prevGroup == 1 ? 2 : 1;
  for (auto child : adj[node])
  {
    if (!dfs(child, groups[node]))
      return false;
  }
  return true;
}

int main()
{
  int n, m;
  cin >> n >> m;
  adj = vector<vector<int>>(n + 1);
  while (m--)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  bool isPossible = true;
  groups = vector<int>(n + 1);
  for (int i = 1; i < n + 1 && isPossible; i++)
  {
    isPossible = dfs(i, 0);
  }

  if (!isPossible)
  {
    cout << "IMPOSSIBLE"
         << "\n";
  }
  else
  {
    for (int i = 1; i < n + 1; i++)
    {
      cout << groups[i] << "\n";
    }
  }
}
