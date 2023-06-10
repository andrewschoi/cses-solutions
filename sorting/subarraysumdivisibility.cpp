#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> values(n);
  for (int i = 0; i < n; i++)
    cin >> values[i];
  map<int, long long> mp;
  mp[0] = 1;
  int pSum = 0;
  long long ans = 0;

  for (int i = 0; i < n; i++)
  {
    pSum += values[i];
    pSum %= n;
    if (pSum < 0)
      pSum += n;
    ans += mp[pSum];
    mp[pSum]++;
  }

  cout << ans << "\n";
}