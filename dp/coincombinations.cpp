#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<long> coins(n);
  for (auto &coin : coins)
    cin >> coin;

  vector<long> dp(x + 1, 0);
  int MOD = 1e9 + 7;
  for (auto &coin : coins)
  {
    if (coin <= x)
    {
      dp[coin] = 1;
    }
  }

  for (int i = 0; i <= x; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i - coins[j] >= 0)
      {
        (dp[i] += dp[i - coins[j]]) %= MOD;
      }
    }
  }

  cout << dp[x] << "\n";
}