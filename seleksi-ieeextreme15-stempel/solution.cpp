#include <bits/stdc++.h>
using namespace std;

const int maxn = 102;
int n;
int a[maxn];
vector<int> ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	a[0] = 0;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++){
		if (a[i] == a[i-1]) ans.push_back(i);
	}
	cout << ans.size() << '\n';
	for (int i=0; i<(int)ans.size(); i++){
		cout << ans[i];
		if (i+1 < (int)ans.size()) cout << ' ';
	}
	cout << '\n';
	return 0;
}