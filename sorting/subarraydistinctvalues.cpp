#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, k;
  cin >> n >> k;
  vector<int> values(n);
  for (auto &val : values)
    cin >> val;

  map<int, int> mp;
  int l = 0, r = 0;
  long long ans = 0;
  while (r < n)
  {
    if (mp.find(values[r]) == mp.end())
    {
      mp[values[r]] = 0;
    }
    mp[values[r]]++;

    while (mp.size() > k)
    {
      mp[values[l]]--;
      if (mp[values[l]] == 0)
        mp.erase(values[l]);
      l++;
    }
    ans += r - l + 1;
    r++;
  }

  cout << ans << "\n";
}