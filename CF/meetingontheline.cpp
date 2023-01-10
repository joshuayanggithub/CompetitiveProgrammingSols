#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    vector<pair<int,int>> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i].first;
    }
    int mi=INT_MAX, ma=0;
    for (int i=0; i<n; ++i) {
        cin >> v[i].second;
        mi = min({mi,v[i].first-v[i].second});
        ma = max(ma, v[i].first+v[i].second);
    }
    int d = (mi + ma)/2;
    cout << d << (((mi+ma)%2 == 1) ? ".5" : "") << "\n";
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