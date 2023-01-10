#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    int a1 = 1;
    int a2 = 1;
    int nona1 = 0;
    int nona2 = 0;
    for (int i=0; i<n; ++i) {
        int which, num; string add;
        cin >> which >> num >> add;
        for (int i=0; i<add.length(); ++i) {
            if (which == 1 && add[i] == 'a') {
                a1 += num;
            }
            else if (which == 1 && add[i] != 'a') {
                nona1 += num;
            }
            if (which == 2 && add[i] == 'a') {
                a2 += num;
            }
            else if (which == 2 && add[i] != 'a') {
                nona2 += num;
            }
        }
        if (nona2 > 0) {
            cout << "YES\n";
        }
        else if (a1<a2 && nona1 == 0) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        //if a1 == a2 and non
    }
}
signed main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}