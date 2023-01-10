#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(k+1);
    int maxbefore = n*m-2-2;
    //there has to be 2 extra spaces not including start and end for
    for (int i=1; i<=k; ++i) {
        cin >> a[i];
    }
    int done = 0;
    for (int i=k; i>=1; --i) {
        int filled = a[i]-1;
        filled -= done;
        int empty = n*m-2-filled;
        if (empty < 2) {
            cout << "TIDAK\n";
            return;
        }
        ++done;
    }
    cout << "YA\n";
}
signed main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}