#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
vector<array<int,3>> v(61);
int mod = 998244353;

void solve() {
    cin >> n;
    cout << v[n][0] << " " << v[n][1] << " " << v[n][2] << "\n";
}

int choose(int n, int k) {
    int ret=1;
    for (int i=n; i>n-k; --i) {
        ret *= i;
        ret /= (n-i+1);
    }
    return ret;
}

int modify(int n) {
    return n%mod;
}
signed main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    v[0][2] = 1;
    for (int i=2; i<=60; i += 2) {
        v[i][0] = v[i-2][1] + choose(i,i/2)/2;
        v[i][2] = v[i-2][2];
        v[i][1] = choose(i,i/2) - v[i][0] - v[i][2];
        v[i][0] = modify(v[i][0]);
        v[i][1] = modify(v[i][1]);
        v[i][2] = modify(v[i][2]);
    }
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
