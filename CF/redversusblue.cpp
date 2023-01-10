#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,r,b;
    cin >> n >> r >> b;
    int x = min(r,b);
    int y = max(r,b);
    char xc = 'R', yc = 'B';
    if (r > b) {
        xc = 'B';
        yc = 'R';
    }
    int div = y/(x+1);
    int rem = y - (x+1)*div;
    string ans = "";
    for (int i=0; i<x+1; ++i) {
        for (int j=0; j<div; ++j) {
            ans += yc;
        }
        if (rem > 0) {
            ans += yc;
            --rem;
        }
        if (i != x) {
            ans += xc;
        }
    }
    cout << ans << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
