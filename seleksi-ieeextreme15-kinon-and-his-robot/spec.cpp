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
    CONS(1 <= N <= 1e3);
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

  void SampleTestCase2()
  {
    Input({"3"});
    Output({"3"});
  }

  void TestCases()
  {
    for (int i = 0; i < 15; i++)
    {
      CASE(N = rnd.nextInt(1, 100));
    }
    for (int i = 0; i < 25; i++)
    {
      CASE(N = rnd.nextInt(100, 1000));
    }
  }
};