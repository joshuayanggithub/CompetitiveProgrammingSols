#include <bits/stdc++.h>
using namespace std;


void solve() {
    int l,r,x,a,b;
    cin >> l >> r >> x;
    cin >> a >> b;
    if (a==b) {
        cout << "0\n";
        return;
    }
    if (abs(a-b) >= x) {
        cout << "1\n";
        return;
    }
    if (abs(r-b) >= x && abs(r-a) >= x) {
        cout << "2\n";
        return;
    }
    if (abs(l-b) >= x && abs(l-a) >= x) {
        cout << "2\n";
        return;
    }
    if ((abs(l-a) >= x && abs(r-b) >= x) || (abs(r-a) >= x && abs(l-b) >= x)) {
        cout << "3\n";
        return;
    }
    cout << "-1\n";
    return;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}