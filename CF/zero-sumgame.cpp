#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;

void solve() {
    cin >> n;
    int lastz = -1;
    int ans =0;
    vector<int> v(n+1);
    vector<int> o(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> o[i];
        v[i] = v[i-1] + o[i];
    }
    int p = 1;
    while (p<=n && o[p] != 0) {
        if (v[p] == 0) {
            ++ans;
        }
        ++p;
    }
    while (p<=n) {
        map<int,int> m;
        int prev = p;
        while (p<=n) {
            if (o[p] == 0 && prev!=p) {
                break;
            }
            m[v[p]]++;
            ++p;
        }
        int ma = 0;
        for (auto&[a,b]: m) {
            ma = max(ma, b);
        }
        ans += ma;
    }
    cout << ans << "\n";
}

signed main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    int t; cin >> t;
    while (t--) {
        solve();
    }
}