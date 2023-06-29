#include <bits/stdc++.h>
using namespace std;

template <class T>
class BIT
{
private:
  int size;
  vector<T> bit;
  vector<T> arr;

public:
  BIT(int size) : size(size), bit(size + 1), arr(size){};
  void set(int ind, int val) { add(ind, val - arr[ind]); }
  void add(int ind, int val)
  {
    arr[ind] += val;
    ind++;
    for (; ind <= size; ind += ind & -ind)
    {
      bit[ind] += val;
    }
  }
  T pref_sum(int ind)
  {
    ind++;
    T total = 0;
    for (; ind > 0; ind -= ind & -ind)
    {
      total += bit[ind];
    }
    return total;
  }
};

int main()
{
  int arr_len;
  int query_num;
  cin >> arr_len >> query_num;
  BIT<long long> bit(arr_len);
  for (int i = 0; i < arr_len; i++)
  {
    int n;
    cin >> n;
    bit.set(i, n);
  }
  for (int q = 0; q < query_num; q++)
  {
    int type, arg1, arg2;
    cin >> type >> arg1 >> arg2;
    if (type == 1)
    {
      bit.set(arg1 - 1, arg2);
    }
    else if (type == 2)
    {
      cout << bit.pref_sum(arg2 - 1) - bit.pref_sum(arg1 - 2) << "\n";
    }
  }
  return 0;
}