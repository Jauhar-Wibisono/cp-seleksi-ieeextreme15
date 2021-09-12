#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

#define MAXN 10000
#define MAXM 10000
#define MAXNM 10000
#define SQRTN 100
#define SQRTM 100

class ProblemSpec : public BaseProblemSpec {
protected:
	int N, M;
    vector<int> B;
    vector<int> X;
    vector<string> grid;
    int ans;

	void InputFormat() {
	  LINE(N,M);
      LINES(grid) % SIZE(N);
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
        CONS(1 <= M && M <= MAXM);
        CONS(1 <= N*M <= MAXNM);
        CONS(isValidGrid(N,M,grid));
    }

private:
    bool isValidGrid(int n, int m, vector<string> grid){
        if (grid.size() != n || grid[0].length() != m) return false;
        for (auto r : grid){
            for (char c : r){
                if (c != 'A' && c != 'B' && c != '.' && c != '#') return false;
            }
        }
        bool adaA = 0, adaB = 0;
        for (auto r : grid){
            for (char c : r){
                if (c == 'A') adaA = 1;
                else if (c == 'B') adaB = 1;
            }
        }
        return (adaA && adaB);
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
        Input({
        	"3 6",
            "......",
            "A....B",
            "......"
        });
        Output({
        	"6"
        });
    }

    void SampleTestCase2() {
        Input({
            "2 6",
            "B....A",
            "##.#.#"
        });
        Output({
            "7"
        });
    }

    void SampleTestCase3() {
        Input({
            "6 3",
            "#A#",
            "#.#",
            "#.#",
            "#.#",
            "#.#",
            "#B#"
        });
        Output({
            "-1"
        });
    }

    void BeforeTestCase(){
    	grid.clear();
    }

    void TestCases() {
        // small tc
        for (int i=1; i<=2; i++){
            CASE(N = 6, M = 6, generateGrid(N,M,0,grid));
        }
        for (int i=1; i<=3; i++){
            CASE(N = 6, M = 6, generateGrid(N,M,30,grid));
        }
        for (int i=1; i<=3; i++){
            CASE(N = 6, M = 6, generateGrid(N,M,75,grid));
        }
        // medium tc
        for (int i=1; i<=2; i++){
            CASE(N = rnd.nextInt(1,10), M = 100/N, generateGrid(N,M,0,grid));
            CASE(M = rnd.nextInt(1,10), N = 100/M, generateGrid(N,M,0,grid));
        }
        for (int i=1; i<=3; i++){
            CASE(N = rnd.nextInt(1,10), M = 100/N, generateGrid(N,M,30,grid));
            CASE(M = rnd.nextInt(1,10), N = 100/M, generateGrid(N,M,30,grid));
        }
        for (int i=1; i<=3; i++){
            CASE(N = rnd.nextInt(1,10), M = 100/N, generateGrid(N,M,75,grid));
            CASE(M = rnd.nextInt(1,10), N = 100/M, generateGrid(N,M,75,grid));
        }
        // large tc
        for (int i=1; i<=2; i++){
            CASE(N = rnd.nextInt(1,SQRTN), M = MAXNM/N, generateGrid(N,M,0,grid));
            CASE(M = rnd.nextInt(1,SQRTM), N = MAXNM/M, generateGrid(N,M,0,grid));
        }
        for (int i=1; i<=3; i++){
            CASE(N = rnd.nextInt(1,SQRTN), M = MAXNM/N, generateGrid(N,M,30,grid));
            CASE(M = rnd.nextInt(1,SQRTM), N = MAXNM/M, generateGrid(N,M,30,grid));
        }
        for (int i=1; i<=3; i++){
            CASE(N = rnd.nextInt(1,SQRTN), M = MAXNM/N, generateGrid(N,M,75,grid));
            CASE(M = rnd.nextInt(1,SQRTM), N = MAXNM/M, generateGrid(N,M,75,grid));
        }
        // flat grid
        CASE(N = 1, M = MAXM, generateGrid(N,M,0,grid));
        CASE(N = MAXN, M = 1, generateGrid(N,M,0,grid));
        CASE(N = 2, M = MAXNM/N, generateGrid(N,M,0,grid));
        CASE(N = MAXNM/2, M = 2, generateGrid(N,M,0,grid));
    }

private:
    void generateGrid(int n, int m, int ratio, vector<string> &grid){
        grid.resize(n);
        for (int i=0; i<n; i++){
            grid[i].resize(m);
            for (int j=0; j<m; j++){
                int gacha = rnd.nextInt(1,100);
                if (gacha <= ratio) grid[i][j] = '#';
                else grid[i][j] = '.';
            }
        }
        int rA = rnd.nextInt(0,n-1);
        int cA = rnd.nextInt(0,m-1);
        int rB = rA, cB = cA;
        while (rB == rA && cB == cA){
            rB = rnd.nextInt(0,n-1);
            cB = rnd.nextInt(0,m-1);
        }
        grid[rA][cA] = 'A';
        grid[rB][cB] = 'B';
    }
};