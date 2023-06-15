#include <bits/stdc++.h>
using namespace std;

int main()
{
  long mod = 1e9 + 7;
  int n;
  cin >> n;
  vector<vector<char>> grid(n, vector<char>(n));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> grid[i][j];
    }
  }

  vector<vector<long>> dp(n, vector<long>(n, 0));

  if (grid[0][0] == '.')
    dp[0][0] = 1;

  for (int i = 1; i < n; i++)
  {
    if (grid[i][0] == '.')
    {
      (dp[i][0] += dp[i - 1][0]) %= mod;
    }
    else
    {
      dp[i][0] = 0;
    }
  }

  for (int j = 1; j < n; j++)
  {
    if (grid[0][j] == '.')
    {
      (dp[0][j] += dp[0][j - 1]) %= mod;
    }
    else
    {
      dp[0][j] = 0;
    }
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (grid[i][j] == '.')
      {
        (dp[i][j] += dp[i - 1][j] + dp[i][j - 1]) %= mod;
      }
      else
      {
        dp[i][j] = 0;
      }
    }
  }

  cout << dp[n - 1][n - 1];
}