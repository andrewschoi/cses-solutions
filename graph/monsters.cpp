#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define pii pair<int, int>
#define mn 1005
using namespace std;

int rlen, clen;
int startR, startC;
deque<pii> monsterLocations;
vector<vector<int>> timeMonsters;
vector<string> grid;
int rAdd, cAdd;
char direction;
vector<tuple<int, int, char>> dirs = {{0, 1, 'R'}, {1, 0, 'L'}, {-1, 0, 'D'}, {1, 0, 'U'}};
vector<vector<tuple<int, int, char>>> previousLocation;
string result = "NO";

int main()
{
  cin >> rlen >> clen;
  grid.resize(rlen);
  timeMonsters.resize(rlen, vector<int>(clen, INT_MAX));
  previousLocation.resize(rlen, vector<tuple<int, int, char>>(clen));
  for (int i = 0; i < rlen; i++)
  {
    cin >> grid[i];
    for (int j = 0; j < clen; j++)
    {
      if (grid[i][j] == 'A')
      {
        startR = i;
        startC = j;
      }
      if (grid[i][j] == 'M')
      {
        monsterLocations.emplace_back(i, j);
        timeMonsters[i][j] = 0;
      }
    }
  }

  while (!monsterLocations.empty())
  {
    auto node = monsterLocations.front();
    int row = node.first, col = node.second;
    monsterLocations.pop_front();
    int newTime = timeMonsters[row][col] + 1;
    for (auto move : dirs)
    {
      tie(rAdd, cAdd, direction) = move;
      int r = row + rAdd, c = col + cAdd;
      if (r < 0 || r >= rlen || c < 0 || c >= clen || grid[r][c] == '#' || timeMonsters[r][c] <= newTime)
      {
        continue;
      }
      timeMonsters[r][c] = newTime;
      monsterLocations.emplace_back(r, c);
    }
  }

  deque<tuple<int, int, char>> location;
  location.emplace_back(startR, startC, 0);
  grid[startR][startC] = '#';
  previousLocation[startR][startC] = {-1, -1, '*'};
  int row, col, time;
  while (!location.empty())
  {
    tie(row, col, time) = location.front();
    location.pop_front();
    if (row == 0 || row == rlen - 1 || col == 0 || col == clen - 1)
    {
      cout << "YES"
           << "\n";
      string path;
      while (row != -1)
      {
        tie(row, col, direction) = previousLocation[row][col];
        path += direction;
      }
      path.pop_back();
      reverse(path.begin(), path.end());
      result += to_string(path.size());
      result += "\n";
      result += path;
      return;
    }
    for (auto move : dirs)
    {
      tie(rAdd, cAdd, direction) = move;
      int r = row + rAdd, c = col + cAdd;
      int newTime = time + 1;
      if (grid[r][c] == '#' || timeMonsters[r][c] <= newTime)
      {
        continue;
      }
      grid[r][c] == '#';
      previousLocation[r][c] = {row, col, direction};
      location.emplace(r, c, newTime);
    }
  }
}