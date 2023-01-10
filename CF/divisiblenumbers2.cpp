#include <bits/stdc++.h>
using namespace std;
#define ll long long
//3 3 8 5 //3 8 3 5
void factorize(ll x, ll y, ll c, ll d) {
    ll product = x * y;
    vector<ll> divisors1;
    for (ll div=1; div*div<=x; ++div) {
        if (x%div == 0) {
            divisors1.push_back(div);
            divisors1.push_back(x/div);
        }
    }
    vector<ll> divisors2;
    for (ll div=1; div*div<=y; ++div) {
        if (y%div == 0) {
            divisors2.push_back(div);
            divisors2.push_back(y/div);
        }
    }
    for (auto&d3: divisors1) {
        for (auto&d4: divisors2) {
            ll d1 = d3*d4;
            ll d2 = product/d1;
            if (d1*d2 == product) {
                ll n1 = d1*(c/d1);
                ll n2 = d2*(d/d2);
                 if (n1 > x && n2 > y) {
                    cout << n1 << " " << n2 << "\n";
                    return;
                }
                n1 = d2*(c/d2);
                n2 = d1*(d/d1);
                if (n1 > x && n2 > y) {
                    cout << n1 << " " << n2 << "\n";
                    return;
                }
            }
        }
    }
    cout << "-1 -1\n";   
}
void solve() {
    ll a,b,c,d; 
    cin >> a >> b >> c >> d;
    factorize(a,b,c,d);
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}