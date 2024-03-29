#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4+4, sqrtn = sqrt(maxn);
int n, q;
vector<int> adjl[maxn];
vector<pair<int, int>> que[maxn];
int sez[maxn], tin[maxn], tout[maxn], ver[maxn], tem;
int sml_ans[sqrtn], cnt[maxn];
int ans[maxn];

void dfs1(int u, int p){
	sez[u] = 1;
	tin[u] = tem;
	ver[tem] = u;
	tem++;
	for (int v : adjl[u]){
		if (v == p) continue;
		dfs1(v, u);
		sez[u] += sez[v]; 
	}
	tout[u] = tem;
}

void dfs2(int u, int p, bool keep){
	int mx = -1, heavy = -1;
	for (int v : adjl[u]){
		if (v == p) continue;
		if (sez[v] > mx){
			mx = sez[v];
			heavy = v;
		}
	}
	for (int v : adjl[u]){
		if (v != p && v != heavy) dfs2(v, u, false);
	}
	if (heavy != -1) dfs2(heavy, u, true);
	for (int i=1; i<sqrtn; i++){
		if (u%i == 0) sml_ans[i]++;
	}
	cnt[u]++;
	for (int v : adjl[u]){
		if (v == p || v == heavy) continue;
		for (int t=tin[v]; t<tout[v]; t++){
			int val = ver[t];
			for (int i=1; i<sqrtn; i++){
				if (val%i == 0) sml_ans[i]++;
			}
			cnt[val]++;
		}
	}
	for (auto p : que[u]){
		if (p.second < sqrtn) ans[p.first] = sml_ans[p.second];
		else{
			ans[p.first] = 0;
			for (int i=p.second; i<=n; i+=p.second) ans[p.first] += cnt[i];
		}
	}
	if (!keep){
		for (int t=tin[u]; t<tout[u]; t++){
			int val = ver[t];
			for (int i=1; i<sqrtn; i++){
				if (val%i == 0) sml_ans[i]--;
			}
			cnt[val]--;
		}
	}
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
	cin >> q;
	for (int i=0; i<q; i++){
		int x, y;
		cin >> x >> y;
		que[x].emplace_back(i, y);
	}
	tem = 0;
	dfs1(1, 0);
	memset(sml_ans, 0, sizeof sml_ans);
	memset(cnt, 0, sizeof cnt);
	dfs2(1, 0, true);
	for (int i=0; i<q; i++) cout << ans[i] << '\n';
	return 0;
}