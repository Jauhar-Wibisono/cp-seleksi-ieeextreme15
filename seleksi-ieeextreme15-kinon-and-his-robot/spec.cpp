#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec
{
protected:
  int N, ans;

  void InputFormat()
  {
    LINE(N);
  }

  void OutputFormat()
  {
    LINE(ans);
  }

  void GradingConfig()
  {
    TimeLimit(1);
    MemoryLimit(64);
  }

  void Constraints()
  {
    CONS(1 <= N <= 1e18);
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec>
{
protected:
  void SampleTestCase1()
  {
    Input({"1"});
    Output({"1"});
  }

  void SampleTestCase1()
  {
    Input({"3"});
    Output({"3"});
  }

  void TestCases()
  {
    for (int i = 0; i < 10; i++)
    {
      CASE(N = rnd.nextInt(1, 1000));
    }
    for (int i = 0; i < 20; i++)
    {
      CASE(N = rnd.nextInt(1e10, 1e18));
    }
  }
};