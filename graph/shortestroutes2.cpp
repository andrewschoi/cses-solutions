#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m, q;
  cin >> n >> m >> q;
  vector<vector<long long>> min_dist(n, vector<long long>(n, 1e18));
  for (int i = 0; i < m; i++)
  {
    int a, b;
    int c;
    cin >> a >> b >> c;
    a--;
    b--;
    if (c < min_dist[a][b])
      min_dist[a][b] = min_dist[b][a] = c;
  }

  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        long long new_dist = min_dist[i][k] + min_dist[k][j];
        if (new_dist < min_dist[i][j])
        {
          min_dist[i][j] = new_dist;
        }
      }
    }
  }

  while (q--)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a == b)
    {
      min_dist[a][b] = 0;
    }
    else if (min_dist[a][b] == 1e18)
    {
      min_dist[a][b] = -1;
    }

    cout << min_dist[a][b] << "\n";
  }
}