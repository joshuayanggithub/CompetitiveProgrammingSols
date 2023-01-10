#include <bits/stdc++.h>
using namespace std;
#define ll long long
//3 3 8 5 //3 8 3 5
void solve() {
    ll a,b,c,d; 
    cin >> a >> b >> c >> d;
    ll product = a*b;
    for (ll div=1; div*div<=product; ++div) {
        if (product%div != 0) {
            continue;
        }
        ll d1 = div;
        ll d2 = product/div;
        ll n1 = d1*(c/d1);
        ll n2 = d2*(d/d2);
        if (n1 > a && n2 > b) {
            cout << n1 << " " << n2 << "\n";
            return;
        }
        n1 = d2*(c/d2);
        n2 = d1*(d/d1);
        if (n1 > a && n2 > b) {
            cout << n1 << " " << n2 << "\n";
            return;
        }
    }
    cout << "-1 -1\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}