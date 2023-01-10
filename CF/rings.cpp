#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    string s; cin >> s;
    int k=-1;
    for (int i=0; i<n; ++i) {
        if (s[i]=='0') {
            k=i;
            break;
        }
    }
    ++k;
    if (k==0)
        cout << 1 << " " << n-1 << " " << 2 << " " << n;
    else if (k<=n/2) 
        cout << k << " " << n << " " << k+1  << " " << n;
    else
        cout << 1 << " " << k << " " << 1 << " " << k-1;
    cout << endl;
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