#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    vector<set<int>> v(n+1);
    for (int i=1; i<=n; ++i) {
        v[i].insert(i);
    }
    for (int i=1; i<=n; ++i) {
        string s; cin >> s;
        for (int j=1; j<=n; ++j) {
            if (s[j-1] == '1') { //set i has to be subset of set j
                for (auto&next: v[i]) {
                    v[j].insert(next);
                }
            }
        }
    }
    for (int i=1; i<=n; ++i) {
        cout << v[i].size() << " ";
        for (auto& next: v[i]) {
            cout << next << " ";
        }
        cout << "\n";
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}