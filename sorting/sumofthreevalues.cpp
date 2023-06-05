#include <bits/stdc++.h>
using namespace std;

int main()
{
  long long n, t;
  cin >> n >> t;

  vector<pair<long long, long long>> values(n);

  for (long long i = 0; i < n; ++i)
  {
    int val;
    cin >> val;
    values[i] = make_pair(val, i + 1);
  }

  sort(values.begin(), values.end());

  for (long long i = 0; i < n; ++i)
  {
    long long lo = 0, hi = n - 1;
    while (lo != hi)
    {
      int target = t - values[i].first;
      if (lo != i && hi != i && values[lo].first + values[hi].first == target)
      {
        cout << values[lo].second << " " << values[i].second << " " << values[hi].second << " ";
        return 0;
      }
      if (values[lo].first + values[hi].first < target)
      {
        lo++;
      }
      else
      {
        hi--;
      }
    }
  }

  cout << "IMPOSSIBLE"
       << "\n";
  return 0;
}