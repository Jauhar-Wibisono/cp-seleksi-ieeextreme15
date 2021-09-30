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
      ret = ret && (1 <= a[i] && a[i] <= 1e5);
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
           "U 2",
           "R 3",
           "D 1",
           "L 5",
           "U 2"});
    Output({"9"});
  }

  void TestCases()
  {
    for (int i = 0; i < 10; i++)
    {
      CASE(N = rnd.nextInt(1, 1000), generateSpiral(N, Dir, Dist));
    }
    for (int i = 0; i < 20; i++)
    {
      CASE(N = rnd.nextInt(1e10, 1e18));
    }
  }

private:
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
};