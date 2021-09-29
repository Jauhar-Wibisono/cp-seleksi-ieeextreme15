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
    if (types == "1")
    {
      int x;
      strin >> x;
      a[itr++] = x;
    }
    if (types == "0")
    {
      if (--itr)
      {
        b[itr - 1] += b[itr];
      }
      b[itr] = 0;
    }
    if (types == "2")
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
  //cout << endl;
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
    if (s == "1")
    {
      cin >> x;
      a += (" " + to_string(x));
    }
    else if (s == "2")
    {
      cin >> x >> y;
      a += (" " + to_string(x));
      a += (" " + to_string(y));
    }
    operations.push_back(a);
  }

  solve(operations);
}
