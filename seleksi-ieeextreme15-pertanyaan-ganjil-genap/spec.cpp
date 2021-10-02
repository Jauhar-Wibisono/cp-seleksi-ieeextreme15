#include <tcframe/spec.hpp>
using namespace tcframe;
using namespace std;

// baru copas

#define MAXN 100000 // bisa digedein kayaknya
#define MAXQ 100000
#define MAXA 1000000000

class ProblemSpec : public BaseProblemSpec
{
protected:
    int N, Q;
    vector<vector<int>> que;
    vector<string> ans;

    void InputFormat()
    {
        LINE(N, Q);
        LINES(que) % SIZE(Q);
    }

    void OutputFormat()
    {
        LINES(ans);
    }

    void GradingConfig()
    {
        TimeLimit(2);
        MemoryLimit(256);
    }

    void Constraints()
    {
        CONS(1 <= N && N <= MAXN);
        CONS(1 <= Q && Q <= MAXQ);
        CONS(isValidQue(N, Q, que));
    }

private:
    bool isValidQue(int n, int q, vector<vector<int>> a)
    {
        if (a.size() != q)
            return false;
        bool ada_3 = false;
        for (auto &v : a)
        {
            if (v.empty())
                return false;
            if ((v[0] == 1 || v[0] == 2))
            {
                if (v.size() != 3)
                    return false;
                if (v[1] < 1 || v[1] > n)
                    return false;
                if (v[2] < 1 || v[2] > MAXA)
                    return false;
            }
            else if (v[0] == 3)
            {
                ada_3 = true;
                if (v.size() != 5)
                    return false;
                for (int i = 1; i < 5; i++)
                {
                    if (v[i] < 1 || v[i] > n)
                        return false;
                }
                if (v[1] > v[3] || v[2] > v[4])
                    return false;
            }
            else
                return false;
        }
        return ada_3;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec>
{
protected:
    void SampleTestCase1()
    {
        Input({"5 5",
               "1 4 1",
               "3 3 3 5 5",
               "2 4 3",
               "3 1 2 4 5",
               "3 1 4 1 4"});
        Output({"Ganjil",
                "Genap",
                "Ganjil"});
    }

    void BeforeTestCase()
    {
        que.clear();
    }

    void TestCases()
    {
        // small tc
        for (int i = 1; i <= 5; i++)
        {
            CASE(N = 10, Q = 10, generateQue(N, Q, que, 10));
            CASE(N = 10, Q = 10, generateQueOddOnly(N, Q, que, 10));
        }
        // medium tc
        for (int i = 1; i <= 5; i++)
        {
            CASE(N = 1000, Q = 1000, generateQue(N, Q, que, MAXA));
            CASE(N = 1000, Q = 1000, generateQueOddOnly(N, Q, que, MAXA));
        }
        // large tc
        for (int i = 1; i <= 5; i++)
        {
            CASE(N = 5, Q = MAXQ, generateQue(N, Q, que, MAXA));
            CASE(N = 5, Q = MAXQ, generateQueOddOnly(N, Q, que, MAXA));
            CASE(N = MAXN, Q = MAXQ, generateQue(N, Q, que, MAXA));
            CASE(N = MAXN, Q = MAXQ, generateQueOddOnly(N, Q, que, MAXA));
        }
        CASE(N = MAXN, Q = MAXQ, generateQueQueryOnly(N, Q, que));
        for (int i = 1; i <= 5; i++)
        {
            CASE(N = MAXN, Q = MAXQ, generateQueUpdateOnly(N, Q, que, MAXA));
        }
    }

private:
    void generateQue(int n, int q, vector<vector<int>> &a, int mx)
    {
        // operasi terakhirnya dibikin query aja biar aman
        for (int i = 0; i < q; i++)
        {
            vector<int> row = {0};
            row[0] = rnd.nextInt(1, 3);
            if (i + 1 < q && (row[0] == 1 || row[0] == 2))
            {
                int pos, val;
                pos = rnd.nextInt(1, n);
                val = rnd.nextInt(1, mx);
                row.push_back(pos);
                row.push_back(val);
                a.push_back(row);
            }
            else
            {
                row[0] = 3;
                int r1, c1, r2, c2;
                r1 = rnd.nextInt(1, n);
                c1 = rnd.nextInt(1, n);
                r2 = rnd.nextInt(1, n);
                c2 = rnd.nextInt(1, n);
                if (r1 > r2)
                    swap(r1, r2);
                if (c1 > c2)
                    swap(c1, c2);
                row.push_back(r1);
                row.push_back(c1);
                row.push_back(r2);
                row.push_back(c2);
                a.push_back(row);
            }
        }
    }

    void generateQueOddOnly(int n, int q, vector<vector<int>> &a, int mx)
    {
        // operasi terakhirnya dibikin query aja biar aman
        for (int i = 0; i < q; i++)
        {
            vector<int> row = {0};
            row[0] = rnd.nextInt(1, 3);
            if (i + 1 < q && (row[0] == 1 || row[0] == 2))
            {
                int pos, val;
                pos = rnd.nextInt(1, n);
                val = rnd.nextInt(0, (mx - 1) / 2) * 2 + 1;
                row.push_back(pos);
                row.push_back(val);
                a.push_back(row);
            }
            else
            {
                row[0] = 3;
                int r1, c1, r2, c2;
                r1 = rnd.nextInt(1, n);
                c1 = rnd.nextInt(1, n);
                r2 = rnd.nextInt(1, n);
                c2 = rnd.nextInt(1, n);
                if (r1 > r2)
                    swap(r1, r2);
                if (c1 > c2)
                    swap(c1, c2);
                row.push_back(r1);
                row.push_back(c1);
                row.push_back(r2);
                row.push_back(c2);
                a.push_back(row);
            }
        }
    }

    void generateQueQueryOnly(int n, int q, vector<vector<int>> &a)
    {
        // jawabannya pasti Genap semua karena nggak update
        for (int i = 0; i < q; i++)
        {
            vector<int> row = {3};
            int r1, c1, r2, c2;
            r1 = rnd.nextInt(1, n);
            c1 = rnd.nextInt(1, n);
            r2 = rnd.nextInt(1, n);
            c2 = rnd.nextInt(1, n);
            if (r1 > r2)
                swap(r1, r2);
            if (c1 > c2)
                swap(c1, c2);
            row.push_back(r1);
            row.push_back(c1);
            row.push_back(r2);
            row.push_back(c2);
            a.push_back(row);
        }
    }

    void generateQueUpdateOnly(int n, int q, vector<vector<int>> &a, int mx)
    {
        for (int i = 0; i < q; i++)
        {
            vector<int> row = {0};
            if (i + 1 < q)
            {
                row[0] = rnd.nextInt(1, 2);
                int pos, val;
                pos = rnd.nextInt(1, n);
                val = rnd.nextInt(0, (mx - 1) / 2) * 2 + 1; // ganjil biar enforce update
                row.push_back(pos);
                row.push_back(val);
                a.push_back(row);
            }
            else
            {
                row[0] = 3;
                int r1, c1, r2, c2;
                r1 = rnd.nextInt(1, n);
                c1 = rnd.nextInt(1, n);
                r2 = rnd.nextInt(1, n);
                c2 = rnd.nextInt(1, n);
                if (r1 > r2)
                    swap(r1, r2);
                if (c1 > c2)
                    swap(c1, c2);
                row.push_back(r1);
                row.push_back(c1);
                row.push_back(r2);
                row.push_back(c2);
                a.push_back(row);
            }
        }
    }
};