#include <bits/stdc++.h>
using namespace std;

vector<int> adj[200005];
int dp[200005][2];

void dfs(int v, int p)
{
  for (int to : adj[v])
  {
    if (to != p)
    {
      dfs(to, v);
      dp[v][0] += max(dp[to][0], dp[to][1]);
    }
  }
  for (int to : adj[v])
  {
    if (to != p)
    {
      dp[v][1] = max(dp[v][1], dp[to][0] + 1 + dp[v][0] - max(dp[to][0], dp[to][1]));
    }
  }
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(0, -1);
  cout << max(dp[0][0], dp[0][1]) << "\n";
}