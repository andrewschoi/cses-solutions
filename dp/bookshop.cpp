#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, x;
  cin >> n >> x;
  vector<int> prices(n);
  for (int i = 0; i < n; i++)
  {
    cin >> prices[i];
  }
  vector<int> pages(n);
  for (int i = 0; i < n; i++)
  {
    cin >> pages[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

  for (int i = 1; i <= n; i++)
  {
    for (int j = 0; j <= x; j++)
    {
      dp[i][j] = dp[i - 1][j];
      if (j - prices[i - 1] >= 0)
      {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - prices[i - 1]] + pages[i - 1]);
      }
    }
  }

  cout << dp[n][x];
}