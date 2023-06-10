#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, t;
  cin >> n >> t;
  vector<int> values(n);
  for (int i = 0; i < n; i++)
  {
    cin >> values[i];
  }
  int j = 0;
  long long sum = 0;
  int i = 0;
  int cnt = 0;
  while (i < n)
  {
    sum += values[i];
    while (sum >= t)
    {
      if (sum == t)
        cnt++;
      sum -= values[j];
      j++;
    }
    i++;
  }

  cout << cnt << "\n";
}