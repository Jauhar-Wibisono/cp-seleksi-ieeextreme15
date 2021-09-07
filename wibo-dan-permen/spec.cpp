#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

// ini emang ada warning output doesnt comform to format gitu

#define MAXN 200000
#define MINA 1
#define MAXA 1000000000

class ProblemSpec : public BaseProblemSpec {
protected:
	int N, M;
    vector<int> A;
    int K;
    vector<int> ans;
    int impossible;

	void InputFormat() {
	  LINE(N, M);
      LINE(A % SIZE(N));
	}

    void OutputFormat2() {
        LINE(K);
        LINE(ans % SIZE(K));
    }

    void OutputFormat1() {
        LINE(impossible);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= MAXN);
        CONS(1 <= M && M < N);
        CONS(isValidA(N, A));
    }

private:
    bool isValidA(int n, vector<int> a){
        if (a.size() != n) return false;
        for (int u : a){
            if (u < MINA || u > MAXA) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
        	"5 4",
            "1 2 3 7 5"
        });
        Output({
        	"2",
            "1 4"
        });
    }

    void SampleTestCase2() {
        Input({
            "5 3",
            "2 2 2 2 2"     
        });
        Output({
            "3",
            "1 3 4"
        });
    }

    void SampleTestCase3() {
        Input({
            "3 2",
            "8 12 16"
        });
        Output({
            "1",
            "1"
        });
    }

    void BeforeTestCase(){
    	A.clear();
    }

    void TestCases() {
        // small tc
        for (int i=1; i<=9; i++){
            CASE(N = 10, M = 9, generateASameElement(N, i, A));
        }
        for (int i=2; i<=19; i++){
            CASE(N = 20, M = rnd.nextInt(i, 19), generateARandom(N, M, A));
        }
        // medium tc
        for (int i=1; i<=20; i++){
            CASE(N = 1000, M = rnd.nextInt(100, N-1), generateARandom(N, M, A));
        }
        // large tc
        for (int i=1; i<=20; i++){
            CASE(N = MAXN, M = rnd.nextInt(1000, N-1), generateARandom(N, M, A));
        }
        // random
        for (int i=1; i<=10; i++) CASE(N = rnd.nextInt(1, MAXN), M = rnd.nextInt(2, N-1), generateARandom(N, M, A));
        // smol values
        for (int i=1; i<=10; i++) CASE(N = MAXN, M = N-1, generateASameElement(N, i, A));
        // coprimes
        CASE(N = MAXN, M = N-1, generateASameElement(N, 7919, A));
        CASE(N = MAXN, M = N-1, generateASameElement(N, 16127, A));
        CASE(N = MAXN, M = N-1, generateASameElement(N, 193939, A));
    }

private:
    void generateASameElement(int n, int x, vector<int> &a){
        for (int i=0; i<n; i++) a.push_back(x);
    }
    void generateARandom(int n, int m, vector<int> &a){
        for (int i=0; i<n; i++){
            int val = 0;
            while (val % m == 0) val = rnd.nextInt(1, MAXA);
            a.push_back(val);
        }
    }
};