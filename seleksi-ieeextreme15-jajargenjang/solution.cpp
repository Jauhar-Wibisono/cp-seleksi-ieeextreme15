#include <bits/stdc++.h>
using namespace std;

long long maxParallel(long long maxed, long long offset){
    long long maxc2 = 20100;
    return (maxed*maxc2 + 2000 + offset)*(maxed*maxc2 + 2000 + offset) - maxed*maxc2*maxc2 - 2000 - offset;
}
long long c2(long long x){
    return x*(x-1)/2;
}

vector<long long> parallel;
void print(){
    long long total = 0, idx = 0;
    for(int i=0; i<parallel.size(); i++){
        total += parallel[i];
        //cout << c2(parallel[i]) << endl;
    }
    cout << total << endl;


    for(int i=-100; i<=100; i++){
        for(int j=0; j<=100; j++){
            if(abs(__gcd(i,j))==1 && idx<parallel.size()){
                for(int k=0; k<parallel[idx]; k++){
                    cout << i << " " << j << " " << -100+k << endl;
                }
                idx++;
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    long long k;
	cin >> k;
	if(k%3 == 2){
        cout << -1 << endl;
        return 0;
	}
	k *= 2;
	long long cpyK, toAdd, nbAvailable;
	long long total = 2000;
	long long sumSquare = 2000;
	while(total*total - sumSquare<k){
        toAdd = 2;
        while(toAdd < 201 && (c2(toAdd+1) + total)*(c2(toAdd+1) + total)-(sumSquare + c2(toAdd+1)*c2(toAdd+1)) < k){
            toAdd++;
        }
        parallel.push_back(toAdd);
        total += c2(toAdd);
        sumSquare += c2(toAdd)*c2(toAdd);
	}

	if(parallel.size() == 0){//kuli greedy
        bool found = false;
        for(int i=2000; 2*c2(i)>=k && !found; i--){
            cpyK = 2*c2(i)-k;
            nbAvailable = i;
            parallel.clear();
            while(nbAvailable>0){
                toAdd = 2;
                while(c2(toAdd) <= nbAvailable && 2*c2(c2(toAdd)) <= cpyK){
                    toAdd++;
                }
                toAdd--;
                parallel.push_back(toAdd);
                cpyK -= 2*c2(c2(toAdd));
                nbAvailable -= c2(toAdd);
            }
            if(cpyK == 0){
                found=  true;
            }
        }
        if(found){
            print();
        }else{
            cout << -1 << endl;
        }
	}else{
        long long offset = 0;
        while(((total+offset)*(total+offset) - (sumSquare+offset) -k)%3 != 0){
            offset++;
        }
        cpyK = (total+offset)*(total+offset) - (sumSquare+offset) -k;
        nbAvailable = 2000 + offset;
        while(nbAvailable>0){
            toAdd = 2;
            while(c2(toAdd) <= nbAvailable && 2*c2(c2(toAdd)) <= cpyK){
                toAdd++;
            }
            toAdd--;
            parallel.push_back(toAdd);
            cpyK -= 2*c2(c2(toAdd));
            nbAvailable -= c2(toAdd);
        }
        print();
	}
}
