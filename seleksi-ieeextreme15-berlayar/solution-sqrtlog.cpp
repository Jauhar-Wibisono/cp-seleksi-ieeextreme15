#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9+7;
const int maxn = 3e4+5, maxd = 3e4+5, sqrtd = sqrt(maxd);
int n, d;
unordered_map<int, int> dp[maxn];
int ans;
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> d;
	dp[d][d] = 1;
	for (int i=d; i<=n; i++){
		for (auto p : dp[i]){
			int j = p.first, val = p.second;
			for (int k=-1; k<=1; k++){
				if (j+k > 0 && i+j+k <= n){
					dp[i+j+k][j+k] = (dp[i+j+k][j+k] + val) % mod;
				}
			}
		}
	}
	ans = 0;
	for (auto p : dp[n]) ans = (ans + p.second) % mod; 
	cout << ans << "\n";
}