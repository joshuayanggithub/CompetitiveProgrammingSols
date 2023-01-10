#include <bits/stdc++.h>
using namespace std;

int n,k;

void solve() {
    cin >> n >> k;
    string s; 
    cin >> s;
    int lasti=-1;
    for (int i=n-1; i>=0; --i) {
        if (s[i] == '1') {
            lasti = i;
            break;
        }
    }
    int distn = n-1-lasti;
    if (lasti != -1 && distn <=k) {
        swap(s[lasti],s[n-1]);
        k-=distn;
    }
    int first=n;
    for (int i=0; i<n-1; ++i) {
        if (s[i] == '1') {
            first = i;
            break;
        }
    }
    int dist0 = first-0;
    if (first != n && dist0 <=k) {
        swap(s[first],s[0]);
        k-=dist0;
    }
    int ans = 0;
    for (int i=0; i<n; ++i) {
        if (i==0 && s[i] == '1')
            ans += 10;
        else if (i==n-1 && s[i] == '1')
            ans += 1;
        else if (s[i] == '1')
            ans += 11;
    }
    cout << ans << "\n";
}

int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    int t; cin >> t;
    while (t--) {
        solve();
    }
}