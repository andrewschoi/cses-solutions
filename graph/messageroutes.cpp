#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  vector<int> dist(N + 1, 1e5 + 10), parent(N + 1);
  vector<vector<int>> adj(N + 1);
  while (M--)
  {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> q;
  dist[1] = 0;
  q.push(1);
  while (!q.empty())
  {
    int x = q.front();
    q.pop();
    for (int t : adj[x])
    {
      if (dist[t] == 1e5 + 10)
      {
        dist[t] = dist[x] + 1;
        parent[t] = x;
        q.push(t);
      }
    }
  }

  if (dist[N] == 1e5 + 10)
  {
    cout << "IMPOSSIBLE";
  }
  else
  {
    cout << dist[N] + 1 << "\n";
    vector<int> v{N};
    while (v.back() != 1)
      v.push_back(parent[v.back()]);
    reverse(v.begin(), v.end());
    for (int t : v)
      cout << t << " ";
  }
}