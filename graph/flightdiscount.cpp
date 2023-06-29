#include <bits/stdc++.h>
using namespace std;

vector<long long> min_costs(int from, const vector<vector<pair<int, int>>> &neighbors)
{
  vector<long long> min_costs(neighbors.size(), INT64_MAX);
  min_costs[from] = 0;

  priority_queue<pair<long long, int>> frontier;
  frontier.push({0, from});
  while (!frontier.empty())
  {
    pair<long long, int> curr_state = frontier.top();
    frontier.pop();
    int curr = curr_state.second;
    if (-curr_state.first != min_costs[curr])
      continue;
    for (auto [n, nc] : neighbors[curr])
    {
      long long new_cost = min_costs[curr] + nc;
      if (new_cost < min_costs[n])
      {
        min_costs[n] = new_cost;
        frontier.push({-new_cost, n});
      }
    }
  }
  return min_costs;
}

int main()
{
  int city_nums;
  int flight_nums;
  cin >> city_nums >> flight_nums;
  vector<vector<pair<int, int>>> neighbors(city_nums);
  vector<vector<pair<int, int>>> reverse_neighbors(city_nums);
  while (flight_nums--)
  {
    int from, to, cost;
    cin >> from >> to >> cost;
    neighbors[--from].push_back({to - 1, cost});
    reverse_neighbors[to - 1].push_back({from, cost});
  }

  vector<long long> start_costs = min_costs(0, neighbors);
  vector<long long> end_costs = min_costs(city_nums - 1, reverse_neighbors);
  long long total_min = INT64_MAX;
  for (int c = 0; c < city_nums; c++)
  {
    for (auto [n, nc] : neighbors[c])
    {
      if (start_costs[c] == INT64_MAX || end_costs[n] == INT64_MAX)
        continue;
      total_min = min(total_min, start_costs[c] + (nc / 2) + end_costs[n]);
    }
  }
  cout << total_min << "\n";
}