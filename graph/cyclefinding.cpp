#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

class triplet
{
public:
  long long first;
  long long second;
  long long third;
};

long long n,
    m;
vector<triplet> edges;
vector<long long> dist;
vector<long long> relaxant;

void bellmanFord()
{
  long long x;
  for (long long i = 1; i <= n; i++)
  {
    x = -1;
    for (auto e : edges)
    {
      long long u = e.first;
      long long v = e.second;
      long long d = e.third;
      if (dist[u] + d < dist[v])
      {
        dist[v] = d + dist[u];
        relaxant[v] = u;
        x = v;
      }
    }
  }

  if (x == -1)
  {
    cout << "NO" << endl;
    return;
  }
  for (long long i = 1; i <= n; i++)
  {
    x = relaxant[x];
  }

  vector<long long> cycle;
  for (long long v = x;; v = relaxant[v])
  {
    cycle.push_back(v);
    if (v == x && cycle.size() > 1)
    {
      break;
    }
  }

  reverse(cycle.begin(), cycle.end());
  cout << "YES"
       << "\n";
  for (auto v : cycle)
  {
    cout << v << ' ';
  }
  cout << endl;
}

int main()
{
  cin >> n >> m;
  dist.resize(n + 1);
  relaxant.resize(n + 1);
  edges.resize(m);

  for (long long i = 0; i < m; i++)
  {
    struct triplet inp;
    cin >> inp.first >> inp.second >> inp.third;
    edges[i] = inp;
  }

  for (long long i = 1; i <= n; i++)
    relaxant[i] = -1;
  bellmanFord();
}