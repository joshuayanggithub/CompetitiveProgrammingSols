#include <bits/stdc++.h>
using namespace std;

long long n,p,k,change;
const int mxN = 1e5+1;
vector<long long> a(mxN);
int precomp[mxN][317];

void solve() {
    cin >> p >> k;
    if (k < change) {
        cout << precomp[p][k] << "\n";
        return;
    }
    int ans=0;
    while (p<=n) {
        p += a[p] + k;
        ++ans;
    }
    cout << ans << "\n";
}

int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
    }
    int t; cin >> t;
    change=sqrt(n);
    for (p=n; p>=1; --p) {
        for (k=1; k<change; ++k) {
            if (p+a[p]+k > n) {
                precomp[p][k] = 1;
            }
            else 
                precomp[p][k] = precomp[p+a[p]+k][k] +1;
        }
    }
    while (t--) {
        solve();
    }
}