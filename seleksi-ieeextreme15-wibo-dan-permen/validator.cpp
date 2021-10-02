#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int EXIT_AC = 42;
const int EXIT_WA = 43;

int wa() {
    exit(EXIT_WA);
}

int ac() {
    exit(EXIT_AC);
}

int main(int argc, char* argv[]) {
    ifstream tc_in(argv[1]);
    ifstream tc_out(argv[2]);
    string feedback_path = argv[3];
    feedback_path += "/judgeerror.txt";
    ofstream feedback(feedback_path);

    int n, m;
    tc_in >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; i++) tc_in >> a[i];

    int k;
    if (!(cin >> k)) {
        feedback << "no input" << endl;
        return wa();
    }
    if (k < 1 || k > n) {
        feedback << "invalid k (answer size)" << endl;
        return wa();
    }

    int sum = 0;
    vector<bool> udah(n+1, false);
    for (int i=0; i<k; i++){
        int idx;
        if (!(cin >> idx)){
            feedback << "not enough indices" << endl;
            return wa();
        }
        if (udah[idx]){
            feedback << "answer contains repeated index" << endl;
            return wa();
        }
        udah[idx] = 1;
        sum += a[idx-1];
        sum %= m;
    }
    int over_idx;
    if (cin >> over_idx){
        feedback << "too many indices" << endl;
        return wa();
    }

    if (sum != 0){
        feedback << "sum is not divisible by m" << endl;
        feedback << "sum mod m = " << sum << ", m = " << m << endl;
        return wa(); 
    }

    return ac();
}