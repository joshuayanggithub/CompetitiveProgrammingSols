#include <bits/stdc++.h>
using namespace std;

int t;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool c3 = false;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        a[i] += a[i]%10;
        if (a[i]%10 == 0 || a[i]%10 == 5)
            c3 = true;
    }
    sort(a.begin(),a.end());
    if (c3) {
        cout << ((a[0] == a[a.size()-1]) ? "yes\n" : "no\n");
        return;
    }
    bool c1 = false, c2 = false;
    for (int i=0; i<n; ++i) {
        while (a[i]%10 != 4) {
            a[i] += a[i]%10;
        }
        if (a[i] % 20 == 4)
            c1 = true;
        else
            c2 = true;
    }
    if (c1 && c2)
        cout << "no" << "\n";
    else 
        cout << "yes" << "\n";
}
int main() {
    cin >> t;
    while (t--) {
        solve();
    }
}