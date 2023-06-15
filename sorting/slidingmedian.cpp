#include <bits/stdc++.h>
using namespace std;
typedef long ll;

ll N, M;
multiset<ll> lo;
multiset<ll> hi;

void ins(ll val)
{
  ll a = *lo.rbegin();
  if (a < val)
  {
    hi.insert(val);
    if (hi.size() > M / 2)
    {
      lo.insert(*hi.begin());
      hi.erase(hi.find(*hi.begin()));
    }
  }
  else
  {
    lo.insert(val);
    if (lo.size() > (M + 1) / 2)
    {
      hi.insert(*lo.rbegin());
      lo.erase(lo.find(*lo.rbegin()));
    }
  }
}

void er(ll val)
{
  if (hi.find(val) != hi.end())
    hi.erase(hi.find(val));
  else
  {
    lo.erase(lo.find(val));
  }
  if (lo.empty())
  {
    lo.insert(*hi.begin());
    hi.erase(hi.find(*hi.begin()));
  }
}

int main()
{
  cin >> N >> M;
  vector<ll> values(N);
  for (ll i = 0; i < N; i++)
    cin >> values[i];
  lo.insert(values[0]);
  for (ll i = 1; i < M; i++)
  {
    ins(values[i]);
  }
  cout << *lo.rbegin() << " ";
  for (ll i = M; i < N; i++)
  {
    if (M == 1)
    {
      ins(values[i]);
      er(values[i - M]);
    }
    else
    {
      er(values[i - M]);
      ins(values[i]);
    }

    cout << *lo.rbegin() << " ";
  }
  cout << "\n";
}