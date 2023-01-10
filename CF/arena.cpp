#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 998244353;

int powed(int x, int times, int e) {
    if (e == 1) {
        return x;
    }
    return powed((x*times)%mod,times,e-1);
}
signed main () {
    int n,x;
    cin >> n >> x;
    int base = powed(x,x,n);
    for (int i = n; i<=x; ++i) {
        base = ((base+mod - (n*powed(i-1,i-1,n-1))%mod))%mod;
    }
    cout << base;
}