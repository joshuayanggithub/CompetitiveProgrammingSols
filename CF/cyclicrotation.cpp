#include <bits/stdc++.h>
using namespace std;
//editorail solved :()
void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    for (int i=0; i<n; ++i) {
        cin >> b[i];
    }
    multiset<int> dups;
    int pa = n-1;
    int pb = n-1;
    while (pa >=0 && pb >=0) {
        while (pb >=1 && b[pb] == b[pb-1]) {
            dups.insert(b[pb]);
            --pb;
        }
        if (b[pb] == a[pa]) {
            --pa;
            --pb;
        }
        else {
            if (dups.count(a[pa])) {
                dups.erase(dups.find(a[pa]));
                --pa;
            }
            else {
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}