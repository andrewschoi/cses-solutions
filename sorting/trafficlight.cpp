#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x, n;
  cin >> x;
  cin >> n;
  set<int> lights{0, x};
  multiset<int> dist{x};

  for (int i = 0; i < n; ++i)
  {
    int pos;
    cin >> pos;
    auto it1 = lights.upper_bound(pos);
    auto it2 = it1;
    --it2;

    dist.erase(dist.find(*it1 - *it2));
    dist.insert(*it1 - pos);
    dist.insert(pos - *it2);
    lights.insert(pos);
    auto ans = dist.end();
    --ans;
    cout << *ans << " ";
  }
  return 0;
}