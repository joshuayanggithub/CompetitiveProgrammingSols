#include <bits/stdc++.h>
using namespace std;

int n,k;
void solve() {
    cin >> n >> k;
    vector<int> a(n);
    set<int> v[n];
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        for (int j=1; j<=k; ++j) {
            v[i].insert(a[i]/j);
        }
    }
    int l=0, r=3000;
    int ans = 3001;
    for (int i=0; i<=3000; ++i) {
        int lowest = 0;
        for (int j=0; j<n; ++j) {
            auto it = v[j].lower_bound(i);
            if (it == v[j].end()) {
                break;
            }
            int closest = *it;
            lowest = max(lowest, closest-i);
            if (j==n-1) ans = min(lowest, ans);
        }
        
    }
    cout << ans << "\n";
}

int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    int t; cin >> t;
    while (t--) {
        solve();
    }
}