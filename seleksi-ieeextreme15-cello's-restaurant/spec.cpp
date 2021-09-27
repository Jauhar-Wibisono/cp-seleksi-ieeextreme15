#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec
{
protected:
  int N;
  string op;
  vector<int> op_num, ans;

  void InputFormat()
  {
    LINE(N);
    LINES(op, op_num) % SIZE(N);
  }

  void OutputFormat()
  {
    LINES(ans) % SIZE(N);
  }

  void GradingConfig()
  {
    TimeLimit(1);
    MemoryLimit(256);
  }

  void Constraints()
  {
    CONS(1 <= N <= 1e9);
    CONS(isValidOperationName(op));
    CONS(isValidOperationNumber(N, op_num));
  }

private:
  bool isValidOperationName(string s)
  {
    return (s == "antri" || s == "selesai" || s == "traktir");
  }

  bool isValidOperationNumber(int n, vector<int> a)
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
    Input({"12",
           "antri 4",
           "selesai"
           "antri 3",
           "antri 5",
           "antri 2",
           "traktir 3 1",
           "selesai",
           "antri 1",
           "traktir 2 2",
           "antri 4"
           "selesai"
           "selesai"});
    Output({"4 EMPTY 3 5 2 3 6 1 1 4 1 8"});
  }

  void TestCases()
  {
    for (int i = 0; i < 10; i++)
    {
      vector<string> op;

      CASE(N = rnd.nextInt(1, 1000));
    }
    for (int i = 0; i < 20; i++)
    {
      CASE(N = rnd.nextInt(1e10, 1e18));
    }
  }
};