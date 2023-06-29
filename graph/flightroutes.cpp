#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n, m, k;
  cin >> n >> m >> k;
  vector<pair<long long, long long>> adj[n + 1];
  for (long long i = 0; i < m; i++)
  {
    long long a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back({b, w});
  }

  priority_queue<pair<long long, long long>> q;
  q.push({0, 1});
  vector<long long> vis(n + 1, 0);
  while (!q.empty() && vis[n] < k)
  {
    long long a = q.top().second;
    long long d = q.top().first;
    q.pop();
    vis[a]++;
    if (a == n)
    {
      cout << -d << "\n";
    }
    if (vis[a] <= k)
    {
      for (auto [b, w] : adj[a])
      {
        q.push({d - w, b});
      }
    }
  }
}