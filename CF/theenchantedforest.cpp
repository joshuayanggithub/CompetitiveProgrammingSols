#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll t,n,k;

void solve() {
    cin >> n >> k;
    int a [n];
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    ll ans = 0;
    if (k<=n) {
        ll sum = 0;
        for (int i=0; i<k; ++i) {
            sum += a[i];
        }
        ans = sum;
        for (int s=1; s<=n-k; ++s) { // n-k n-1
            sum = sum - a[s-1] + a[s+k-1];
            ans = max(ans, sum); 
        }   
        ans += k*(k-1)/2;
    }
    else {
        for (int i=0; i<n; ++i) {
            ans += a[i];
        }
        ans += (k*n - n*(n+1)/2);
    }
    cout << ans << "\n";
}
int main() {
    cin >> t;
    while (t--) {
        solve();
    }
}