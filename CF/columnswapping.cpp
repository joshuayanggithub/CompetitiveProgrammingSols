#include <bits/stdc++.h>
using namespace std;

int n,m;

void solve() {
    cin >> n >> m;
    int grid[n][m];
    int sortedgrid[n][m];
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            cin >> grid[i][j];
            sortedgrid[i][j] = grid[i][j];
        }
        sort(sortedgrid[i],sortedgrid[i]+m);
    }
    vector<int> v;
    for (int c=0; c<m; ++c) {
        for (int r=0; r<n; ++r) {
            if (grid[r][c] != sortedgrid[r][c]) {
                v.push_back(c);
                break;
            }
        }
    }
    if (v.size() == 0) {
        cout << "1 1\n";
        return;
    }
    for (int r=0; r<n; ++r) {
        swap(grid[r][v[0]], grid[r][v[1]]);
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (grid[i][j] != sortedgrid[i][j]) {
                cout << "-1\n";
                return;
            }
        }
    }
    cout << v[0]+1 << " " << v[1]+1 << "\n";
}

int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    int t; 
    cin >> t;
    while (t--) {
        solve();
    }
}