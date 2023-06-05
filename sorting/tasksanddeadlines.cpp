#include <bits/stdc++.h>

using namespace std;

struct range
{
  long long duration, deadline;

  bool operator<(const range &other)
  {
    return duration < other.duration;
  }
};

int main()
{
  long long n;
  cin >> n;
  vector<range> tasks(n);
  long long ans = 0;
  long long time = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> tasks[i].duration >> tasks[i].deadline;
  }

  sort(tasks.begin(), tasks.end());

  for (int i = 0; i < n; i++)
  {
    time += tasks[i].duration;
    ans += (time - tasks[i].deadline);
  }

  cout << -ans << "\n";
  return 0;
}