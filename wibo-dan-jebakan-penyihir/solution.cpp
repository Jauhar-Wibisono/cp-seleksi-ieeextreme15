#include <bits/stdc++.h>
using namespace std;

struct state{
	int r, c, p1, p2, p3, d;
	state(){}
	state(int r, int c, int p1, int p2, int p3, int d): r(r), c(c), p1(p1), p2(p2), p3(p3), d(d) {}
};

int n, m;
vector<string> grid;
queue<state> q;
vector<vector<vector<vector<vector<bool>>>>> vis; // vis[row][col][prev][2nd prev][3rd prev]
pair<int,int> finish;
int ans = -1;
const int dr[] = {0,-1,-1,-1,0,1,1,1,0}, dc[] = {1,1,0,-1,-1,-1,0,1};

bool invalid(int r, int c, int p1, int p2, int p3){
	return (r < 0 || c < 0 || r >= n || c >= m || vis[r][c][p1][p2][p3] || grid[r][c] == '#');
}

int main(){
	cin >> n >> m;
	// resize and init vector
	grid.resize(n);
	vis.resize(n);
	for (int i1=0; i1<n; i1++){
		vis[i1].resize(m);
		for (int i2=0; i2<m; i2++){
			vis[i1][i2].resize(9);
			for (int i3=0; i3<9; i3++){
				vis[i1][i2][i3].resize(9);
				for (int i4=0; i4<9; i4++){
					vis[i1][i2][i3][i4].assign(9,0);
				}
			}
		}
	}
	for (int i=0; i<n; i++) cin >> grid[i];
	for (int i=0; i<n; i++){
		for (int j=0; j<m; j++){
			if (grid[i][j] == 'A') q.push(state(i,j,8,8,8,0));
			else if (grid[i][j] == 'B') finish = {i,j};
		}
	}
	while (!q.empty()){
		state s = q.front();
		q.pop();
		if (invalid(s.r,s.c,s.p1,s.p2,s.p3)) continue;
		vis[s.r][s.c][s.p1][s.p2][s.p3] = 1;
		if (make_pair(s.r,s.c) == finish){
			if (ans == -1) ans = s.d;
			else ans = min(ans,s.d);
		}
		for (int i=0; i<8; i++){
			if (i == s.p1 || i == s.p2 || i == s.p3) continue;
			q.push(state(s.r+dr[i],s.c+dc[i],i,s.p1,s.p2,s.d+1));
		}
	}
	cout << ans << "\n";
}