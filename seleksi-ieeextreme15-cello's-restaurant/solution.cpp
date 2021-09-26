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
    if (types == "antri")
    {
      int x;
      strin >> x;
      a[itr++] = x;
    }
    if (types == "selesai")
    {
      if (--itr)
      {
        b[itr - 1] += b[itr];
      }
      b[itr] = 0;
    }
    if (types == "traktir")
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
    cout << " ";
  }
}

int main()
{
  vector<string> op;
  int n;
  cin >> n;
  vector<string> operations;
  for (int i = 0; i < n; i++)
  {
    string s;
    int x = -1, y = -1;
    cin >> s;
    string a;
    a += s;
    if (s == "antri")
    {
      cin >> x;
      a += (" " + to_string(x));
    }
    else if (s == "traktir")
    {
      cin >> x >> y;
      a += (" " + to_string(x));
      a += (" " + to_string(y));
    }
    operations.push_back(a);
  }

  solve(operations);
}
