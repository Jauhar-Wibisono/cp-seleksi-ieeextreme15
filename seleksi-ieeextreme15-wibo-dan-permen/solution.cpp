#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+4;
int n, m, a[maxn];
int pref[maxn];
int pos[maxn];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		a[i] %= m;
	}
	memset(pos, -1, sizeof pos);
	pref[0] = 0;
	pos[0] = 0;
	for (int i=1; i<=n; i++){
		pref[i] = (pref[i-1] + a[i]) % m;
		if (pos[pref[i]] != -1){
			cout << i - pos[pref[i]] << endl;
			for (int j=pos[pref[i]]+1; j<=i; j++) cout << j << ' ';
			cout << endl;
			return 0;
		}
		pos[pref[i]] = i;
	}
	return 0;
}