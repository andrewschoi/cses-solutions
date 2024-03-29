#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

const int MAX_INT = 2e5;
int N;
int ans[MAX_INT];
vector<pair<pair<int, int>, int>> v(MAX_INT);

int main()
{
  cin >> N;
  v.resize(N);
  for (int i = 0; i < N; i++)
  {
    cin >> v[i].first.first >> v[i].first.second;
    v[i].second = i;
  }

  sort(v.begin(), v.end());
  int rooms = 0, last_room = 0;
  priority_queue<pair<int, int>> pq;

  for (int i = 0; i < N; i++)
  {
    if (pq.empty())
    {
      last_room++;
      pq.push(make_pair(-v[i].first.second, last_room));
      ans[v[i].second] = last_room;
    }
    else
    {
      pair<int, int> minimum = pq.top();
      if (-minimum.first < v[i].first.first)
      {
        pq.pop();
        pq.push(make_pair(-v[i].first.second, minimum.second));
        ans[v[i].second] = minimum.second;
      }
      else
      {
        last_room++;
        pq.push(make_pair(-v[i].first.second, last_room));
        ans[v[i].second] = last_room;
      }
    }

    rooms = max(rooms, int(pq.size()));
  }

  cout << rooms << "\n";
  for (int i = 0; i < N; i++)
    cout << ans[i] << " ";
}