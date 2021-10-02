#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int EXIT_AC = 42;
const int EXIT_WA = 43;
const int maxn = 100000;

int wa() {
    exit(EXIT_WA);
}

int ac() {
    exit(EXIT_AC);
}

long long c2(long long x){
    return x*(x-1)/2;
}

int main(int argc, char* argv[]) {
    ifstream tc_in(argv[1]);
    ifstream tc_out(argv[2]);
    string feedback_path = argv[3];
    feedback_path += "/judgeerror.txt";
    ofstream feedback(feedback_path);

    //Masukin k soal
    long long k;
    tc_in >> k;

    //Masukin banyak line peserta
    long long n;
    if (!(cin >> n)) {
        feedback << "no input" << endl;
        return wa();
    }
    //Harusnya gaada jawaban klo k == 2 mod 3
    if(n == -1){
        long long njudge;
        tc_out >> njudge;
        if(njudge == -1){
            return ac();
        }else{
            feedback << "not providing solution" << endl;
            return wa();
        }
    }
    //Maksimal 1e5
    if (n < 0 || n > maxn ) {
        feedback << "invalid n (answer size)" << endl;
        return wa();
    }

    //Masukin n pers garis peserta
    long long a, b, c;
    vector<pair<long long, long long> > cnt[201][101];
    for (int i=0; i<n; i++){
        if (!(cin >> a >> b >> c)){
            feedback << "not enough indices" << endl;
            return wa();
        }
        if(a<-100 || a>100 || b<-100 || b>100 || c<-100 || c>100){
            feedback << "a/b/c out of bounds" << endl;
            return wa();
        }

        //Cari gradien pecahan paling sederhana dari a/b dengan penyebut positif
        long long d = abs(__gcd(a, b));
        if(b<0){d = -d;}
        if(d == 0){//Cuma masuk if ini kalau a = b = 0
            feedback << "not a line" << endl;
            return wa();
        }
        //Simpan bentuk paling sederhana c/d, buat dibandingkan apakah peserta memberikan garis sama persis nantinya
        long long e = abs(__gcd(c, d));
        if(d<0){e = -e;}

        //Garis gradien sama dimasukin ke vektor yang sama
        cnt[100 + a/d][b/d].push_back({c/e, d/e});
    }
    //Kalau masih ada line
    string dummy;
    if(cin >> dummy){
        feedback << "too much indices" << endl;
        return wa();
    }

    //Mau cek apakah ada garis yang persis sama, sekaligus ngitung banyak jajargenjang
    long long ans=0, tot=0, toAdd;
    for(int i=0; i<=200; i++){
        for(int j=0; j<=100; j++){
            sort(cnt[i][j].begin(), cnt[i][j].end());
            for(int k=1; k<cnt[i][j].size(); k++){
                if(cnt[i][j][k] == cnt[i][j][k-1]){
                    feedback << "terdapat garis sama" << endl;
                    return wa();
                }
            }
            toAdd = c2(cnt[i][j].size());
            tot += toAdd;
            ans += toAdd*toAdd;
        }
    }

    if(2*k != tot*tot - ans){
        feedback << "jumlah jajar genjang tidak sama: " << 2*k << " " << tot*tot-ans << endl;
        return wa();
    }

    return ac();
}