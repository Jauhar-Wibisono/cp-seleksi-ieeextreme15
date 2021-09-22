#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

// baru copas

#define MAXN 100000
#define MAXXY 100000
#define MAXAB 1000000000

class ProblemSpec : public BaseProblemSpec {
protected:
	int N;
    vector<int> X, Y, A, B;
    long long ans;

	void InputFormat() {
        LINE(N);
        LINES(X, Y, A, B) % SIZE(N);
	}

    void OutputFormat() {
        LINE(ans);
    }

    void GradingConfig() {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints() {
        CONS(1 <= N && N <= MAXN);
        CONS(isValidVec(N, -MAXXY, MAXXY, X));
        CONS(isValidVec(N, -MAXXY, MAXXY, Y));
        CONS(isValidVec(N, 0, MAXAB, A));
        CONS(isValidVec(N, 0, MAXAB, B));
    }

private:
    bool isValidVec(int n, int l, int r, vector<int> v){
        if(v.size() != n) return false;
        for(int i=0; i<n; i++){
            if(v[i] < l) return false;
            if(v[i] > r) return false;
        }
        return true;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
        	"4",
            "1 4 0 0",
            "3 2 0 0",
            "4 3 0 4",
            "2 1 4 0"
        });
        Output({
        	"18",
        });
    }

    void TestCases() {
        // small tc
        for (int i=1; i<=5; i++){
            CASE(N=rnd.nextInt(1,1000), X=generateVec(N, -1000, 1000), Y=generateVec(N, -1000, 1000), A=generateVec(N, 0, 0), B=generateVec(N, 0, 0));
        }
        for (int i=1; i<=10; i++){
            CASE(N=rnd.nextInt(1,1000), X=generateVec(N, -1000, 1000), Y=generateVec(N, -1000, 1000), A=generateVec(N, 0, 1e5), B=generateVec(N, 0, 1e5));
        }
        for (int i=1; i<=5; i++){
            CASE(N=rnd.nextInt(1000,MAXN), X=generateVec(N,-MAXXY,MAXXY), Y=generateVec(N,-MAXXY,MAXXY), A=generateVec(N,0,0), B=generateVec(N,0,0));
        }
        for (int i=1; i<=10; i++){
            CASE(N=rnd.nextInt(1000,MAXN), X=generateVec(N,-MAXXY,MAXXY), Y=generateVec(N,-MAXXY,MAXXY), A=generateVec(N,0,MAXAB), B=generateVec(N,0,MAXAB));
        }
    }

private:
    vector<int> generateVec(int n, int l, int r){
        vector<int> ret;
        for(int i=0; i<n; i++){
            ret.push_back(rnd.nextInt(l,r));
        }
        return ret;
    }
};