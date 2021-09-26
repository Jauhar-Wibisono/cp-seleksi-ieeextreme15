#include <bits/stdc++.h>
using namespace std;

void solve(vector<string> ops)
{
  int n = ops.size();
  vector<int> a(n), b(n);

  int itr = 0;
  for (string op : ops)
  {
    stringstream strin(op);

    string types;
    strin >> types;
    if (types == "push")
    {
      int x;
      strin >> x;
      a[itr++] = x;
    }
    if (types == "pop")
    {
      if (--itr)
      {
        b[itr - 1] += b[itr];
      }
      b[itr] = 0;
    }
    if (types == "inc")
    {
      int x, y;
      strin >> x >> y;
      b[x - 1] += y;
    }

    if (!itr)
    {
      cout << "EMPTY";
    }
    else
    {
      cout << a[itr - 1] + b[itr - 1];
    }
    cout << endl;
    for (auto ax : b)
    {
      cout << ax << endl;
    }
    cout << " ";
  }
}

int main()
{
  vector<string> op;
  int n;
  cin >> n;
  vector<string> operations = {"push 4", "push 8", "inc 1 1", "inc 2 1", "pop", "pop"};
  solve(operations);
}
