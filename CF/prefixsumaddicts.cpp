#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k;

void solve() {
    cin >> n >> k;
    vector<int> a(k);
    for (int i=0; i<k; ++i) {
        cin >> a[i];
    }
    int last = INT_MAX;
    for (int i=k-1; i>=1; --i) {
        if (a[i] - a[i-1] > last) {
            cout << "NO\n"; return;
        }
        last = a[i]-a[i-1];
    }
    if (last*(n-k+1) < a[0])
        cout << "NO\n";
    else
        cout << "YES\n";
    return;
}
signed main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}