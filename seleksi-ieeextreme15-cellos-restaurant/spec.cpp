#include <tcframe/spec.hpp>
using namespace tcframe;

class ProblemSpec : public BaseProblemSpec
{
protected:
  int N;
  string op;
  string ans;
  vector<vector<int>> op_num;

  void InputFormat()
  {
    LINE(N);
    LINES(op_num);
  }

  void OutputFormat()
  {
    RAW_LINE(ans);
  }

  void GradingConfig()
  {
    TimeLimit(1);
    MemoryLimit(256);
  }

  void Constraints()
  {
    CONS(1 <= N <= 1e5);
    CONS(isValidOperationNumber(N, op_num));
  }

private:
  bool isValidOperationNumber(int n, vector<vector<int>> a)
  {
    bool ret = a.size() == n;
    // for (int i = 0; i < a.size(); i++)
    // {
    //   for (int j = 0; j < a[i].size(); j++)
    //   {
    //     ret = ret && (1 <= a[i][j] && a[i][j] <= 1e5);
    //   }
    //   ret = ret && ((a[i][0] == 0) || (a[i][0] == 1) || (a[i][0] == 2));
    // }
    return true;
  }
};

class TestSpec : public BaseTestSpec<ProblemSpec>
{
protected:
  void SampleTestCase1()
  {
    Input({
        "12",
        "1 4",
        "0",
        "1 3",
        "1 5",
        "1 2",
        "2 3 1",
        "0",
        "1 1",
        "2 2 2",
        "1 4",
        "0",
        "0",
    });
    Output({"4 EMPTY 3 5 2 3 6 1 1 4 1 8"});
  }

  void SampleTestCase2()
  {
    Input({"3",
           "1 4",
           "1 3",
           "1 5"});
    Output({"4 3 5 "});
  }

  void BeforeTestCase()
  {
    op_num.clear();
  }

  void TestCases()
  {
    for (int i = 0; i < 1; i++)
    {
      CASE(N = rnd.nextInt(1, 1e3), generateOperationsRandom(N, op_num));
    }
    for (int i = 0; i < 2; i++)
    {
      CASE(N = rnd.nextInt(1e3, 1e5), generateOperationsRandom(N, op_num));
    }
  }

private:
  void generateOperationsRandom(int n, vector<vector<int>> &a)
  {
    int AntriCount = 1;
    a.push_back({1, rnd.nextInt(1, 1e5)});
    for (int i = 1; i < n; i++)
    {
      vector<int> v;
      int currOp = 1;
      if (AntriCount > 1)
      {
        currOp = rnd.nextInt(0, 2);
      }
      else
      {
        currOp = rnd.nextInt(1, 2);
      }

      if (currOp == 0)
      {
        AntriCount--;
        v.push_back(0);
      }
      else if (currOp == 1)
      {
        AntriCount++;
        v.push_back(1);
        v.push_back(rnd.nextInt(1, 1e5));
      }
      else
      {
        v.push_back(2);
        int upper_bound = rnd.nextInt(1, AntriCount);
        v.push_back(rnd.nextInt(1, AntriCount / upper_bound));
        v.push_back(rnd.nextInt(AntriCount / upper_bound, AntriCount));
      }
      a.push_back(v);
    }
  }
};