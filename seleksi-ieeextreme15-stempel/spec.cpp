#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 100

class ProblemSpec : public BaseProblemSpec {
protected:
	int N;
    vector<int> A;
    int M;
    vector<int> B;

	void InputFormat() {
        LINE(N);
        LINE(A % SIZE(N));
	}

    void OutputFormat() {
    	LINE(M);
        LINE(B % SIZE(M));
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= MAXN);
        CONS(isValidArr(N, A));
    }

private:
    bool isValidArr(int n, vector<int> a){
        if (a.size() != n) return false;
        for (int i=0; i<n; i++){
            if (a[i] > i+1) return false;
            if (i > 0 && a[i]-a[i-1] > 2) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
        	"6",
            "0 1 2 3 3 4"
        });
        Output({
        	"2",
            "1 5"
        });
    }

    void SampleTestCase2() {
        Input({
            "1",
            "1"
        });
        Output({
            "0",
            ""
        });
    }

    void BeforeTestCase(){
    	A.clear();
    }

    void TestCases() {
        for (int i=1; i<=5; i++){
            CASE(N = rnd.nextInt(1, 20), generateARandom(N, A));
            CASE(N = rnd.nextInt(1, 10), generateAMonotone(N, A));
        }
        CASE(N = rnd.nextInt(1, 20), generateAAsc(N, A));
        for (int i=1; i<=5; i++){
            CASE(N = 100, generateARandom(N, A));
            CASE(N = 100, generateAMonotone(N, A));
        }
        CASE(N = 100, generateAAsc(N, A));
    }

private:
    void generateARandom(int n, vector<int> &a){
        for (int i=0; i<n; i++){
            int p = (i == 0 ? 0 : a[i-1]);
            a.push_back(rnd.nextInt(p, p+1));
        }
    }
    void generateAAsc(int n, vector<int> &a){
        for (int i=0; i<n; i++) a.push_back(i+1);
    }
    void generateAMonotone(int n, vector<int> &a){
        bool udah = false;
        for (int i=0; i<n; i++){
            if (rnd.nextInt(1, n) == 1) udah = true;
            if (udah){
                if (i == 0) a.push_back(0);
                else a.push_back(a[i-1]);
            }
            else{
                if (i == 0) a.push_back(1);
                else a.push_back(a[i-1] + 1);
            }
        }
    }
};