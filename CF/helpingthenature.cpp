#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<long long> a(200001);

void solve() {
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    long long ans = 0;
    long long offset = 0;
    if (n==1) {
        cout << abs(a[0]) << "\n";
        return;
    }
    for (int i=0; i<n; ++i) {
        if (i == n-1) {
            if (a[i] < a[i-1]) {
                ans += a[i-1] - a[i];
                a[i-1] = a[i];
                ans += abs(0-a[i]);
            }
            else {
                ans += a[i] - a[i-1];
                a[i] = a[i-1];
                ans += abs(0-a[i]);
            }
            cout << ans << "\n";
            return;
        }
        a[i+1] += offset;
        if (a[i] > a[i+1]) {
            ans += a[i] - a[i+1];
            a[i] = a[i+1];
        }
        else if (a[i] < a[i+1]) {
            ans += a[i+1] - a[i];
            offset -= a[i+1] - a[i];
            a[i+1] = a[i];
        }
    }
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