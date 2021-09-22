#include <bits/stdc++.h>
#include <tcframe/spec.hpp>

using namespace std;
using namespace tcframe;
using ll = long long;

const int MAXN = 50000;
const int MAXQ = 50000;

class ProblemSpec : public BaseProblemSpec {
protected:
    int N, Q;
    vector<int> U, V;
    vector<int> X, Y;
    vector<int> ans;

    void InputFormat() {
        LINE(N);
        LINES(U, V) % SIZE(N-1);
        LINE(Q);
        LINES(X, Y) % SIZE(Q);
    }

    void OutputFormat() {
        LINES(ans) % SIZE(Q);
    }

    void GradingConfig() {
        TimeLimit(1);
        MemoryLimit(128);
    }

    void Constraints() {
        CONS(1 <= N && N <= MAXN);
        CONS(eachElementBetween(U, 1, N));
        CONS(eachElementBetween(V, 1, N));
        CONS(noSelfLoop(U, V));
        CONS(isConnected(N, U, V));
    }

private:
    bool eachElementBetween(const vector<int>& v, int lo, int hi) {
        for (int x : v) {
            if (x < lo || x > hi) {
                return false;
            }
        }
        return true;
    }

    bool noSelfLoop(const vector<int>& u, const vector<int>& v) {
    	int len = u.size();
    	for (int i = 0; i < len; i++) {
    		if (u[i] == v[i]) return false;
    	}
    	return true;
    }

    bool isConnected(int n, const vector<int>& u, const vector<int>& v) {
        vector<bool> isVisited(n+1);
        vector<vector<int>> adj(n+1);
        for (int i = 0; i < u.size(); i++) {
            adj[u[i]].push_back(v[i]);
            adj[v[i]].push_back(u[i]);
        }
        int numNodesVisited = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            if (isVisited[now]) {
                continue;
            }
            isVisited[now] = true;
            ++numNodesVisited;
            for (int v : adj[now]) {
                q.push(v);
            }
        }
        return numNodesVisited == n;
    }
};

class TestSpec : public BaseTestSpec<ProblemSpec> {
protected:
    void SampleTestCase1() {
    	Input({
            "7",
            "1 2",
            "3 2",
            "6 1",
            "2 5",
            "6 7",
            "7 4",
            "7",
            "2 1",
            "1 2",
            "1 3",
            "6 4",
            "5 5",
            "3 6",
            "4 7"
    	});
    	Output({
            "3",
            "3",
            "2",
            "1",
            "1",
            "0",
            "0"
    	});
    }

    void BeforeTestCase() {
        U.clear();
        V.clear();
        X.clear();
        Y.clear();
        ans.clear();
    }

    void TestCases() {
        // small tc
        for (int i=1; i<=3; i++){
            CASE(N = rnd.nextInt(2, 10), randomTree(N, U, V), Q = 100, generateQue(N, Q, X, Y, 0, 1, N));
            CASE(N = rnd.nextInt(2, 10), randomLinear(N, U, V), Q = 100, generateQue(N, Q, X, Y, 0, 1, N));
        }
        // medium tc
        for (int i=1; i<=2; i++){
            CASE(N = 1000, randomTree(N, U, V), Q = 1000, generateQue(N, Q, X, Y, 0, 1, N));
            CASE(N = 1000, randomLinear(N, U, V), Q = 1000, generateQue(N, Q, X, Y, 0, 1, N));
        }
        // large tc
        for (int i=1; i<=2; i++){
            CASE(N = MAXN, randomTree(N, U, V), Q = MAXQ, generateQue(N, Q, X, Y, 0, 1, N));
            CASE(N = MAXN, randomLinear(N, U, V), Q = MAXQ, generateQue(N, Q, X, Y, 0, 1, N));
        }
        // stress test
        CASE(N = MAXN, randomTree(N, U, V), Q = MAXQ, generateQue(N, Q, X, Y, 1, 1, N)); // X = 1
        CASE(N = MAXN, randomLinear(N, U, V), Q = MAXQ, generateQue(N, Q, X, Y, 1, 1, N)); // X = 1
        CASE(N = MAXN, randomTree(N, U, V), Q = MAXQ, generateQue(N, Q, X, Y, 0, 1, 1)); // Y = 1
        CASE(N = MAXN, randomLinear(N, U, V), Q = MAXQ, generateQue(N, Q, X, Y, 0, 1, 1)); // Y = 1
        CASE(N = MAXN, randomTree(N, U, V), Q = MAXQ, generateQue(N, Q, X, Y, 0, 1, 10)); // small Y
        CASE(N = MAXN, randomLinear(N, U, V), Q = MAXQ, generateQue(N, Q, X, Y, 0, 1, 10)); // small Y
        CASE(N = MAXN, randomTree(N, U, V), Q = MAXQ, generateQue(N, Q, X, Y, 0, N-10, N)); // large Y
        CASE(N = MAXN, randomLinear(N, U, V), Q = MAXQ, generateQue(N, Q, X, Y, 0, N-10, N)); // large Y
    }

private:
    void renumberAndShuffleEdges(int n, vector<int>& u, vector<int>& v) {
        vector<int> permutation;
        for (int i = 0; i < n; i++) {
            permutation.push_back(i);
        }
        rnd.shuffle(permutation.begin(), permutation.end());
        for (int i = 0; i < u.size(); i++) {
            u[i] = permutation[u[i]] + 1;
            v[i] = permutation[v[i]] + 1;
        } 
        permutation.clear();
        for (int i = 0; i < (int)u.size(); i++){
            permutation.push_back(i);
        }
        rnd.shuffle(permutation.begin(), permutation.end());
        vector<int> nu(u.size()), nv(v.size());
        for (int i = 0; i < (int)u.size(); i++){
            nu[i] = u[permutation[i]];
            nv[i] = v[permutation[i]];
        }
        u = nu, v = nv;
        // cout << n << '\n';
        // for (int i=0; i<(int)u.size(); i++) cout << u[i] << ' ' << v[i] << '\n';
    }

    void randomTree(int n, vector<int>& u, vector<int>& v) {
        for (int i = 1; i < n; i++) {
            u.push_back(i);
            v.push_back(rnd.nextInt(0, i - 1));
        }
        renumberAndShuffleEdges(n, u, v);
    }

    void randomLinear(int n, vector<int> &u, vector<int> &v){
        for (int i=1; i<n; i++){
            u.push_back(i-1);
            v.push_back(i);
        }
        renumberAndShuffleEdges(n, u, v);
    }

    void generateQue(int n, int q, vector<int> &x, vector<int> &y, int vx, int miny, int maxy){
        for (int i=0; i<q; i++){
            if (vx == 0) x.push_back(rnd.nextInt(1, n)); // random node number
            else x.push_back(vx); // same node number
            y.push_back(rnd.nextInt(miny, maxy));
        }
        // cout << q << '\n';
        // for (int i=0; i<q; i++) cout << x[i] << ' ' << y[i] << '\n';
    }
};