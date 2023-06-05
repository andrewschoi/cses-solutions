#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<long long> times(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> times[i];
  }

  sort(times.begin(), times.end());

  long long sum = 0;
  for (int i = 0; i < n - 1; ++i)
  {
    sum += times[i];
  }

  if (sum > times[n - 1])
    cout << sum + times[n - 1] << "\n";
  else
    cout << 2 * times[n - 1] << "\n";
}