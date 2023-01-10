#include <bits/stdc++.h>
using namespace std;

long long n;

void solve() {
    cin >> n;
    vector<long long> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    long long ans = a[n-1];
    vector<long long> diff;
    for (int i=1; i<n; ++i) {
        diff.push_back(a[i]-a[i-1]);
    }
    for (int i=0; i<diff.size(); ++i) {
        ans -= (diff[i]*(n-1-i)*(i+1));
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