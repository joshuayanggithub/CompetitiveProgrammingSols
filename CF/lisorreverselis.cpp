#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    map<int,int> m;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        m[a]++;
    }
    int ans=0;
    int unsure = 0;
    for (auto& [a,b]: m) {
        if (b>1)
            ++ans;
        else
            ++unsure;
    }
    cout << ans+(unsure+1)/2 << "\n";
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