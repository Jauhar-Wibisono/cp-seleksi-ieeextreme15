#include <bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;
long long pangkat(long long a, long long b){
    b %= (mod-1);
    long long ret = 1;
    while(b>0){
        if(b%2){ret = ret*a%mod;}
        a = a*a%mod;
        b /= 2;
    }
    return ret;
}
long long inv(long long a){
    return pangkat(a, mod-2);
}

long long n, a, c, ans;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	c = 1;
	ans = 0;
	for(int i=0; i<n; i++){
        c = c*(n+1-i)%mod*inv(i+1)%mod;
        cin >> a;
        ans = (ans + a*(c-1))%mod;
	}
	cout << ans << endl;
}
