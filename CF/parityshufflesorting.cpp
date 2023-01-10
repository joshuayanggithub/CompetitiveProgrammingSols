#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) cin >> v[i];
    int last = 0;
    for (int i=0; i<n; ++i) {
        if (v[i]%2 == v[0]%2) {
            last = i;
        }
    }
    cout << n-1 << "\n";
    for (int i=0; i<n; ++i) {
        if (i==last)continue;
        if (v[i]%2==v[last]%2) {
            cout << i+1 << " " << last+1 << "\n";
        }
        else {
            cout << 1 << " " << i+1 << "\n";
        }
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}