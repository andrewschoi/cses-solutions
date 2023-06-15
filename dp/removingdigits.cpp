#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> dp(n + 10, 1e7);
  for (int i = 0; i <= 9; i++)
  {
    dp[i] = 1;
  }

  for (int i = 10; i <= n; i++)
  {
    for (char c : to_string(i))
    {
      dp[i] = min(dp[i], 1 + dp[i - (c - '0')]);
    }
  }

  cout << dp[n] << "\n";
}