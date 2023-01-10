#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n); 
    bool works = true;
    for (int i=0; i<n; ++i) {
        int num; cin >> num;
        if (i==0)
            a[0] = num;
        else {
            if (num != 0 && a[i-1] - num >= 0) {
                works = false;
            }
            a[i] = a[i-1] + num;
        }
    }
    if (!works) {
        cout << "-1\n";
        return;
    }
    for (int i=0; i<n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}