#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int r,c; cin >> r >> c;
    ll square = (ll) (max(r,c))*max(r,c);
    if (max(r,c)%2 == 0) { //square is on (row,0)
        square -= ((c-1)+max(r,c)-r);
    }
    else {
        square -= ((r-1)+max(r,c)-c);
    }
    cout << square << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}