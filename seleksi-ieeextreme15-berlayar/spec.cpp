#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 30000
#define MAXD 30000

class ProblemSpec : public BaseProblemSpec {
protected:
    int n, d;
    int ans;

	void InputFormat() {
        LINE(n, d);
	}

    void OutputFormat() {
    	LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= n && n <= MAXN);
        CONS(1 <= d && d <= n);
    }

private:

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
        	"5 2"
        });
        Output({
        	"4"
        });
    }

    void SampleTestCase2() {
        Input({
            "5 4"
        });
        Output({
            "0"
        });
    }

    void SampleTestCase3() {
        Input({
            "21487 4"
        });
        Output({
            "631858925"
        });
    }

    void TestCases() {
        for (int i=1; i<=5; i++) CASE(n = rnd.nextInt(10, 50), d = rnd.nextInt(1, 10));
        for (int i=1; i<=5; i++) CASE(n = rnd.nextInt(10, 50), d = rnd.nextInt(1, n));
        for (int i=1; i<=5; i++) CASE(n = rnd.nextInt(100, 1000), d = rnd.nextInt(1, 10));
        for (int i=1; i<=5; i++) CASE(n = rnd.nextInt(100, 1000), d = rnd.nextInt(1, n));
        for (int i=1; i<=5; i++) CASE(n = rnd.nextInt(MAXN/2, MAXN), d = rnd.nextInt(1, 10));
        for (int i=1; i<=5; i++) CASE(n = rnd.nextInt(MAXN/2, MAXN), d = rnd.nextInt(1, n));
        for (int i=1; i<=3; i++) CASE(n = rnd.nextInt(1, MAXN), d = n);
        CASE(n = MAXN, d = 1);
        CASE(n = 1, d = 1);
    }

private:

};