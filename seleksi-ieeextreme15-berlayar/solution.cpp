#include <bits/stdc++.h>
using namespace std;
 
const int mod = 1e9+7;
const int maxn = 3e4+5, maxd = 3e4+5, sqrtd = sqrt(maxd);
int n, d;
int dp[maxn][6*sqrtd+55];
int ans;
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> d;
	memset(dp, 0, sizeof dp);
	dp[d][3*sqrtd] = 1;
	// ans = 0;
	for (int i=d; i<=n; i++){
		for (int j=0; j<=6*sqrtd; j++){
			int add = j + d - 3*sqrtd;
			// bool finish = true;
			for (int k=-1; k<=1; k++){
				if (add+k > 0 && i+add+k <= n){
					// finish = false;
					dp[i+add+k][j+k] = (dp[i+add+k][j+k] + dp[i][j]) % mod;
				}
			}
			// if (finish) ans = (ans + dp[i][j]) % mod;
		}
	}
	ans = 0;
	for (int i=0; i<=6*sqrtd; i++) ans = (ans + dp[n][i]) % mod; 
	cout << ans << "\n";
}