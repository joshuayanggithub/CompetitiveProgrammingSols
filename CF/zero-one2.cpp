#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,x,y;

void solve() {
    cin >> n >> x >> y;
    string a,b; 
    cin >> a; 
    cin >> b;
    vector<int> change;
    for (int i=0; i<n; ++i) {
        if (a[i] != b[i]) {
            change.push_back(i);
        }
    }
    if (change.size()%2 == 1) {
        cout << "-1\n";
        return;
    }
    int ans = 0;
    if (change.size()==2 && change[0]+1 == change[1]) {
        ans = min(x,2*y);
    }
    else if (y <= x){
        ans = change.size()/2*y;
    }
    else if (x<y) {
        int div = y/x;
        for (int i=0; i<change.size()-1; ++i) {
            if (change[i+1] - change[i] <= div) {
                ans += (change[i+1] - change[i])*x;
            }
        }
    }
    cout << ans << "\n";
}
signed main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}