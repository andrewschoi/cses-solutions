#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, t;
  cin >> n >> t;
  vector<int> times(n);

  for (int i = 0; i < n; i++)
  {
    cin >> times[i];
  }

  long long lo = 0;
  long long hi = 1e18;
  long long ans = 0;
  while (lo <= hi)
  {
    long long mid = (lo + hi) / 2;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum += (mid / times[i]);
      if (sum > t)
      {
        break;
      }
    }
    if (sum >= t)
    {
      ans = mid;
      hi = mid - 1;
    }
    else
    {
      lo = mid + 1;
    }
  }
  cout << ans << "\n";
}