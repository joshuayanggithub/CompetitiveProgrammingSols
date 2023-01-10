#include <bits/stdc++.h>
using namespace std;

int n,m;

void solve() {
    cin >> n >> m;
    if (m<n) { //edge cases
        cout << "NO\n";
        return;
    }
    int notones = (n%2 == 0) ? 2 : 1;
    int numones = n-notones;
    int left = m - numones*1;
    if (left%notones == 1) {
        cout << "NO\n";
        return;
    }
     cout << "YES\n";
    for (int i=0; i<numones; ++i) {
        cout << 1 << " ";
    }
    for (int i=0; i<notones; ++i) {
        int num =  (left/notones);
        cout << num << " ";
    }
    cout << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}