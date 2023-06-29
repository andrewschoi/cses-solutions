#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> visited;
bool found = false;

void dfs(int node, int parent, vector<int> &path)
{
  if (found)
  {
    return;
  }

  if (visited[node])
  {
    if (path.size() > 2)
    {
      found = true;
      int count = 1;
      string result = "";
      result += to_string(node) + " ";
      for (int i = path.size() - 1; i >= 0; i--)
      {
        result += to_string(path[i]);
        count++;
        if (path[i] == node)
        {
          break;
        }
        else
        {
          result += " ";
        }
      }
      cout << to_string(count) << "\n"
           << result << "\n";
      return;
    }
  }

  visited[node] = true;
  path.push_back(node);
  for (auto child : adj[node])
  {
    if (child == parent)
      continue;
    dfs(child, node, path);
  }
  path.pop_back();
}

int main()
{
  cin >> n >> m;
  adj = vector<vector<int>>(n + 1);
  visited = vector<bool>(n + 1);
  while (m--)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  for (int i = 1; i < n + 1; i++)
  {
    if (visited[i])
      continue;
    vector<int> path;
    dfs(i, -1, path);
  }

  if (!found)
    cout << "IMPOSSIBLE";
}