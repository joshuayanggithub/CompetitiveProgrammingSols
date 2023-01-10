#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    int a[n][n];
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<=i+(n-1)/2; ++j) {
            int j2 = j%n;
            a[i][j2] = 1;
            a[j2][i] = -1;
        }
        int col = (i+n/2)%n;
        if (n%2 == 0) //0 indexed so n is even
            a[i][col] = 0;
    }
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            cout << a[i][j] << " ";
        }
    }
    cout << "\n";
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