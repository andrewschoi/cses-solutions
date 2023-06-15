#include <bits/stdc++.h>
using namespace std;

int main()
{
  int mod = 1e9 + 7;
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (int &coin : coins)
    cin >> coin;
  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
  dp[0][0] = 1;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= x; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (j - coins[i - 1] >= 0)
      {
        (dp[i][j] += dp[i][j - coins[i - 1]]) %= mod;
      }
    }
  }

  cout << dp[n][x] << "\n";
}