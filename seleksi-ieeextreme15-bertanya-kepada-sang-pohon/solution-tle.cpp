#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+4;
int n;
vector<int> adjl[maxn];
int tin[maxn], tout[maxn], tem;
int q;

void dfs(int u, int p){
	tin[u] = tem;
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
		for (int i=y; i<=n; i+=y){
			if (tin[i] >= tin[x] && tout[i] <= tout[x]) ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}