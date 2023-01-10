#include <bits/stdc++.h>
//this is such a good problem, but i needed a hint to start 
using namespace std;

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    map<int,int> m;
    int pre = 0;
    for (int i=1; i<=n; ++i) {
        int a = s[i-1] - '0';
        pre += a;
        m[pre-i]++;
    }
    long long ans = 0;
    for (auto&[a,b]: m) {
        if (a==0)
            ans += b;
        ans += (long long)b*(b-1)/2;
    }
    cout << ans << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}