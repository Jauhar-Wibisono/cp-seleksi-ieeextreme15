#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+4; // mungkin digedein?
int n, q;
int bit[2][maxn];

void update(int i, int j){
	while (j <= n){
		bit[i][j]++;
		j += j&-j;
	}
}

int query(int i, int j){
	int ret = 0;
	while (j > 0){
		ret += bit[i][j];
		j -= j&-j;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	memset(bit, 0, sizeof bit);
	while (q--){
		int type;
		cin >> type;
		if (type != 3){
			int i, x;
			cin >> i >> x;
			if (x&1) update(type == 2, i);
		}
		else{
			int r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;
			int sum = (query(0, r2) - query(0, r1 - 1)) * (c2 - c1 + 1) + (query(1, c2) - query(1, c1 - 1)) * (r2 - r1 + 1);
			cout << ((sum&1) ? "Ganjil\n" : "Genap\n");
		}
	}
	return 0;
}