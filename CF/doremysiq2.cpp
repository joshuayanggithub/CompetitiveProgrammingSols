#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
    }
    int curq = 0;
    vector<int> ans(n);
    for (int i=n-1; i>=0; --i) {
        if (v[i] <= curq) {
            ans[i] = 1;
        }
        else if (v[i] > curq && curq < q) {
            ans[i] = 1;
            ++curq;
        }
        else {
            ans[i] = 0;
        }
    }
    for (auto next: ans) {
        cout << next;
    }
    cout << "\n";
}
int main () {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}