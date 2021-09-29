#include <bits/stdc++.h>
using namespace std;

// lol salah, ini solusi kalo querynya
// "berapa node di subtree node x yang nomornya [membagi habis] y_i?"

const int maxn = 5e4+4;
int n, q;
vector<int> adjl[maxn];
int tin[maxn], tout[maxn], pos[maxn], tem;

void dfs(int u, int p){
	tin[u] = tem;
	pos[tem] = u;
	tem++;
	for (int v : adjl[u]){
		if (v == p) continue;
		dfs(v, u);
	}
	tout[u] = tem;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i=1; i<n; i++){
		int u, v;
		cin >> u >> v;
		adjl[u].push_back(v);
		adjl[v].push_back(u);
	}
	tem = 0;
	dfs(1, 0);
	cin >> q;
	while (q--){
		int x, y;
		cin >> x >> y;
		int ans = 0;
		for (int i=1; i*i<=y; i++){
			if (y%i == 0){
				if (tin[i] >= tin[x] && tout[i] <= tout[x]) ans++;
				if (i*i != y && tin[y/i] >= tin[x] && tout[y/i] <= tout[x]) ans++;
			}
		}
		cout << ans << '\n';
	}
}