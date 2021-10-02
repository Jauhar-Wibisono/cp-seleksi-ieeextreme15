#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

// baru copas

#define MAXK 1000000000

class ProblemSpec : public BaseProblemSpec {
protected:
	int K;
    long long N;
    vector <int> A, B, C;

	void InputFormat() {
        LINE(K);
	}

    void OutputFormat1() {
        LINE(N);
        LINES(A, B, C) % SIZE(N);
    }
    void OutputFormat2() {
        LINE(N);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= K && K <= MAXK);
    }

};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
        	"2",
        });
        Output({
        	"-1",
        });
    }

    void TestCases() {
        // small tc (40)
        for (int i=1; i<=60; i++){
            if(i%3 != 2){
                CASE(K=i);
            }
        }
        // impossible tc (5)
        for (int i=0; i<5; i++){
            CASE(K = 3*(rnd.nextInt(1, MAXK/3)-1) + 2);
        }
        // big tc (15)
        for (int i=0; i<14; i++){
            CASE(K = 3*rnd.nextInt(100, MAXK/3) + i%2);
        }
        CASE(K = MAXK);
    }
};