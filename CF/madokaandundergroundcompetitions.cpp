#include <bits/stdc++.h>
using namespace std;

int n,k,r,c;

void solve() {
    cin >> n >> k >> r >> c;
    char grid[n][n];
    r--; c--;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<n; ++j) {
            if ((r+c)%k == (i+j)%k) {
                cout << 'X';
            }
            else {
                cout << '.';
            }
            
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