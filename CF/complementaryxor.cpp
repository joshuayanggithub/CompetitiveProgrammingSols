#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string a,b;
    cin >> n >> a >> b;
    int numones =0;
    bool alld = true, alls = true;
    for (int i=0; i<n; ++i) {
        if (a[i] != b[i]) {
            alls = false;
        }
    }
     for (int i=0; i<n; ++i) {
        if (a[i] == b[i]) {
            alld = false;
        }
    }
    vector<pair<int,int>> ans;
    if (!alls && !alld) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i=0; i<n; ++i) {
        if (a[i] == '1') {
            ans.push_back({i+1,i+1});
        }
    }
    if ((a[0] != b[0] && ans.size()%2 == 0) || (a[0] == b[0] && ans.size()%2 == 1) ) {
        ans.push_back({1,1});
        ans.push_back({2,n});
        ans.push_back({1,n});
    }
    cout << ans.size() << "\n";
    for (auto next: ans) {
        cout << next.first << " " << next.second << "\n";
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}