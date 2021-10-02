#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  ll arr[N];
  int R = 0;
  for (int i = 0; i < N; i++)
  {
    int op;
    cin >> op;
    if (op == 0)
    {
      R--;
    }
    else if (op == 1)
    {
      ll x;
      cin >> x;
      arr[R++] = x;
    }
    else
    {
      ll x, y;
      cin >> x >> y;
      for (int j = 0; j < x; j++)
      {
        arr[j] += y;
      }
    }
    if (R == 0)
    {
      cout << "EMPTY"
           << ' ';
    }
    else
    {
      cout << arr[R - 1] << ' ';
    }
  }
  cout << endl;
}