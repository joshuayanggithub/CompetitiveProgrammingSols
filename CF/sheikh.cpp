#include <bits/stdc++.h>
using namespace std;

int n,q;
int bit[200001][30];
int bitsums[200001][30];

void solve() {
    cin >> n >> q;
    vector<int> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        for (int j=0; j<30; ++j) {
            if (a[j] & (1<<j)) {
                bit[i][j] = 1;
            }
            if (i>0)
                bitsums[i][j] += bitsums[i][j-1];
            bitsums[i][j] += bit[i][j];
        }
    }
    for (int i=0; i<q; ++i) {
        int a,b; cin >> a >> b;
        for (int j=29; j>=0; --j) {
            int diff = bitsums[b][j] - bitsums[a][j];
            if (diff)
        }
    }
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