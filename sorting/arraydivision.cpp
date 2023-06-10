#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> values(n);
  int maxValue = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> values[i];
    maxValue = max(maxValue, values[i]);
  }
  ll lo = maxValue;
  ll hi = 1e18;
  ll maximumSum = 1e18;
  while (lo <= hi)
  {
    ll mid = (lo + hi) / 2;
    int blocks = 1;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
      if (sum + values[i] > mid)
      {
        sum = 0;
        blocks++;
      }
      sum += values[i];
    }
    if (blocks > k)
    {
      lo = mid + 1;
    }
    else
    {
      hi = mid - 1;
      if (mid < maximumSum)
      {
        maximumSum = mid;
      }
    }
  }
  cout << maximumSum << "\n";
}