#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec
{
protected:
  long long N, ans;
  vector<char> Dir;
  vector<int> Dist;

  void InputFormat()
  {
    LINE(N);
    LINES(Dir, Dist);
  }

  void OutputFormat()
  {
    LINE(ans);
  }

  void GradingConfig()
  {
    TimeLimit(1);
    MemoryLimit(256);
  }

  void Constraints()
  {
    CONS(1 <= N <= 1e5);
    CONS(isValidDirection(N, Dir));
    CONS(isValidDistance(N, Dist));
  }

private:
  bool isValidDirection(int n, vector<char> a)
  {
    bool ret = a.size() == n;
    for (int i = 0; i < a.size(); i++)
    {
      ret = ret && (a[i] == 'N' || a[i] == 'E' || a[i] == 'S' || a[i] == 'W');
    }
    return ret;
  }

  bool isValidDistance(int n, vector<int> a)
  {
    bool ret = a.size() == n;
    for (int i = 0; i < a.size(); i++)
    {
      ret = ret && (1 <= a[i] && a[i] <= 1e9);
    }
    return ret;
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec>
{
protected:
  void SampleTestCase1()
  {
    Input({"5",
           "N 2",
           "E 3",
           "S 1",
           "W 5",
           "N 2"});
    Output({"9"});
  }

  void BeforeTestCase()
  {
    Dist.clear();
    Dir.clear();
  }

  void TestCases()
  {
    for (int i = 0; i < 5; i++)
    {
      CASE(N = 4, generateRectangle(N, Dir, Dist));
    }
    for (int i = 0; i < 10; i++)
    {
      CASE(N = rnd.nextInt(100, 1e5), generateSpiral(N, Dir, Dist));
    }
    for (int i = 0; i < 10; i++)
    {
      CASE(N = (3 * rnd.nextInt(1, 1e3)), generateStair(N, Dir, Dist));
    }
    for (int i = 0; i < 10; i++)
    {
      CASE(N = (3 * rnd.nextInt(1e3, 2e4)), generateStair(N, Dir, Dist));
    }
  }

private:
  void generateRectangle(int n, vector<char> &a, vector<int> &b)
  {
    string dir = "NESW";
    int x = rnd.nextInt(100000, 1e9);
    int y = rnd.nextInt(100000, 1e9);
    a.push_back(dir[0]);
    b.push_back(x);
    a.push_back(dir[1]);
    b.push_back(y);
    a.push_back(dir[2]);
    b.push_back(x);
    a.push_back(dir[3]);
    b.push_back(y);
  }

  void generateSpiral(int n, vector<char> &a, vector<int> &b)
  {
    string dir = "NESW";
    int i = 0;
    while (i < n)
    {
      int j = 0;
      while (j < 2 && i < n)
      {
        a.push_back(dir[i % 4]);
        b.push_back(i + 1);
        i++;
        j++;
      }
    }
  }

  void generateStair(int n, vector<char> &a, vector<int> &b)
  {
    string dir1 = "NE";
    string dir2 = "WS";

    for (int i = 0; i < n / 3; i++)
    {
      if (i % 2)
      {
        a.push_back(dir1[i % 2]);
        b.push_back(rnd.nextInt(1, 1000));
      }
      else
      {
        a.push_back(dir1[i % 2]);
        b.push_back(rnd.nextInt(1, 1000));
      }
    }
    for (int i = 0; i < n / 3; i++)
    {
      a.push_back('S');
      b.push_back(rnd.nextInt(1, 1000));
    }
    for (int i = 0; i < n / 3; i++)
    {
      a.push_back('W');
      b.push_back(rnd.nextInt(10, 1000));
    }
  }
};