#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;

  unordered_map<int, int> index;
  int ans = 0;
  for (int i = 0, j = 0; i < n; ++i)
  {
    int num;
    cin >> num;
    j = max(index[num], j);
    ans = max(ans, i - j + 1);
    index[num] = i + 1;
  }
  cout << ans << "\n";
  return 0;
}