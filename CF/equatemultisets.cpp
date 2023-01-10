#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    map<int, int, greater<int>> a;
    map<int, int> b;
    for (int i=0; i<n; ++i) {
        int temp; cin >> temp;
        while (temp%2 ==0) temp/=2;
        a[temp]++;
    }
    for (int i=0; i<n; ++i) {
        int temp; cin >> temp;
        while (temp) {
            b[temp]++;
            temp /= 2;
        }
    }
    for (auto& [k, v]: a) {
        int temp = k;
        while (temp) {
            b[temp]-= v;
            if (b[temp] < 0) {
                cout << "NO\n";
                return;
            }
            temp /=2;
        }
    }
    cout << "YES\n";
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