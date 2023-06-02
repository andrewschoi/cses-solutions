#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int sum = (n * (n + 1)) / 2;
  if (sum % 2 == 1)
  {
    cout << "NO";
    return 0;
  }
  printf("%s", "YES\n");
  for (int i = 2; i <= n / 2; i += 2)
    printf("%d %d ", i, n - i + 1);
  printf("\n%d\n", n / 2);
  for (int i = 1; i <= n / 2; i += 2)
    printf("%d %d ", i, n - i + 1);
  return 0;
}