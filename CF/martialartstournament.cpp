#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int j=0; j<t; ++j) {
        int n;
        cin >> n;
        int w[n];
        for (int i=0; i<n; ++i) {
            cin >> w[i];
        }
        sort(w,w+n);
        vector<pair<int,int>> weights;
        weights.push_back({w[0],1});
        for (int i=1; i<n; ++i) {
            if (w[i] != w[i-1]) {
                weights.push_back({w[i],1});
            }
            else {
                ++weights[weights.size()-1].second;
            }
        }
        int minadd = INT_MAX;
        int p = 0;
        for (int pow = 1; pow<=n; pow *= 2) {
            int sofar = 0;
            int extra = 0;
            while (p<weights.size()) {
                if (sofar + weights[p].second <= pow) {
                    sofar += weights[p].second;
                    ++p;
                }
                else {
                    break;
                }
            }
            extra = pow - sofar;
            for (int pow2 = 0; p+pow <= n; pow2 *= 2) {
                int p2 = p;
                if (pow2 <0) {
                    pow2 = 1;
                }
                int total = extra;
                int sofar2 = 0;
                while (p2<weights.size()) {
                    if (sofar2 + weights[p2].second <= pow2) {
                        sofar2 += weights[p2].second;
                        ++p;
                    }
                    else {
                        break;
                    }
                }
                total += pow2 - sofar2;
                int left = n - sofar - sofar2;
                int pow3 =1;
                while (left > pow3) {
                    pow3 *= 2;
                }
                total += (pow3 - left);
                if (pow2 == 0) {
                    total += 1;
                    pow2 = -1;
                }
                minadd = min(minadd, total);
            }  
        }
        cout << minadd << "\n";
    }
}



/*
4
4
3 1 2 1
1
1
6
2 2 2 1 1 1
8
6 3 6 3 6 3 6 6
*/