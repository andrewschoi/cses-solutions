#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n, t;
  cin >> n >> t;
  vector<int> values(n);
  for (auto &val : values)
  {
    cin >> val;
  }

  map<int, pair<int, int>> valuesToPosition;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (valuesToPosition.count(t - values[i] - values[j]))
      {
        cout << i + 1 << " " << j + 1 << " " << valuesToPosition[t - values[i] - values[j]].first + 1 << " " << valuesToPosition[t - values[i] - values[j]].second + 1 << "\n";
        return 0;
      }
    }
    for (int k = 0; k < i; k++)
    {
      valuesToPosition[values[i] + values[k]] = {i, k};
    }
  }

  cout << "IMPOSSIBLE"
       << "\n";
  return 0;
}