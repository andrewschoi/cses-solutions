#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, answer = 0;
  cin >> n;
  vector<int> seen(n);
  for (int i = 0; i < n; ++i)
    cin >> seen[i];
  sort(seen.begin(), seen.end());
  for (int i = 1; i < n; ++i)
    if (seen[i] != seen[i - 1])
      answer++;
  cout << answer + 1 << endl;
}