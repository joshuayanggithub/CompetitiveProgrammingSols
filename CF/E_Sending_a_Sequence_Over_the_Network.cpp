#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> v(n+1);
    vector<bool> dp(n+1);
    for (int i=1; i<=n; ++i) cin >> v[i]; 
    dp[0] = true;
    for (int i=1; i<=n; ++i) {
        dp[i] = (dp[i] | (i-v[i]-1 >= 0 && dp[i-v[i]-1]) );
        if (i+v[i] <=n) {
            dp[i+v[i]] = (dp[i+v[i]] |  dp[i-1]);
        }
    }
    cout << (dp[n] ? "YES" : "NO");
    cout << "\n";
} 

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}