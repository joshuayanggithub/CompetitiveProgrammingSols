#include <bits/stdc++.h>
using namespace std;

int n,m,a,b,c,d;

void solve() {
    cin >> n >> m >> a >> b >> c >> d;
    cout << min((a<=c) ? (c-a) : (2*n-a-c), (b<=d) ? (d-b) : (2*m-b-d))  << "\n";
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