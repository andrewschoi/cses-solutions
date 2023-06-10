#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> values(n);
  for (auto &val : values)
  {
    cin >> val;
  }

  map<long long, int> mp;
  mp[0] = 1;
  long long pSum = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    pSum += values[i];
    ans += mp[pSum - x];
    mp[pSum]++;
  }

  cout << ans << "\n";
}