#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

signed main() {
    int n; cin >> n;
    for (int i=1; i<=n; ++i) {
        ll total = (i*i)*(i*i-1)/2;
        total -= 4*(i-1)*(i-2); //consider 2 by 3 regions
        cout << total << "\n";
    }
}