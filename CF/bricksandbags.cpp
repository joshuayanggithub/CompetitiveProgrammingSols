#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n; cin >> n;
    vector<int> v(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for (int i=1; i<=n-2; ++i) {
        ans = max (ans,v[n] - v[i] + v[i+1] - v[i]);
    }
    for (int i=3; i<=n; ++i) {
        ans = max (ans,v[i] - v[1] + v[i] - v[i-1]);
    }
    cout << ans << "\n";
}
signed main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}