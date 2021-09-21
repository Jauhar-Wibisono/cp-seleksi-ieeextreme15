#include <bits/stdc++.h>
using namespace std;

const long long maxn = 131072;

long long n;
long long l, r, m, ans;
long long x[maxn], y[maxn], a[maxn], b[maxn];

long long getgradx(long long m){
    long long ret = 0;
    for(int i=0; i<n; i++){
        ret += max((m-x[i])*(m-x[i]), a[i]) - max((m-1-x[i])*(m-1-x[i]), a[i]);
    }
    return ret;
}

long long getdisx(long long m){
    long long ret = 0;
    for(int i=0; i<n; i++){
        ret += max((m-x[i])*(m-x[i]), a[i]);
    }
    return ret;
}

long long getgrady(long long m){
    long long ret = 0;
    for(int i=0; i<n; i++){
        ret += max((m-y[i])*(m-y[i]), b[i]) - max((m-1-y[i])*(m-1-y[i]), b[i]);
    }
    return ret;
}

long long getdisy(long long m){
    long long ret = 0;
    for(int i=0; i<n; i++){
        ret += max((m-y[i])*(m-y[i]), b[i]);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++){
        cin >> x[i] >> y[i] >> a[i] >> b[i];
	}
	l = -1e6; r = 1e6;
	while(r-l>1){
        m = (l+r)/2;
        if(getgradx(m)>0){
            r = m;
        }else{
            l = m;
        }
	}
	ans = getdisx(l);

	l = -1e6; r = 1e6;
	while(r-l>1){
        m = (l+r)/2;
        if(getgrady(m)>0){
            r = m;
        }else{
            l = m;
        }
	}
	ans += getdisy(l);
	cout << ans << endl;
}
