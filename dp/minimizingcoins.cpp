#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x;
	cin >> n >> x;
	vector<long> coins(n);
	for (int i = 0; i < n; i++)
		cin >> coins[i];
	vector<long> dp(x + 1, 1e7);
	dp[0] = 0;
	for (long &coin : coins)
	{
		if (coin <= x)
			dp[coin] = 1;
	}

	for (int i = 0; i <= x; i++)
	{
		for (long &coin : coins)
		{
			if (i - coin >= 0)
			{
				dp[i] = min(dp[i], 1 + dp[i - coin]);
			}
		}
	}
	if (dp[x] != 1e7)
		cout << dp[x] << "\n";
	else
		cout << -1 << "\n";
}