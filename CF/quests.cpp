#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,c,d;

void solve() {
    cin >> n >> c >> d;
    vector<int> coins(n);
    for (int i=0; i<n; ++i) {
        cin >> coins[i];
    }
    sort(coins.begin(),coins.end(),greater<int>());
    int l=0,r=d+1;
    while (l<r) {
        int k =(l+r+1)/2;
        int count =0;
        int days=1;
        while (days<=d ) {
            int ind= (days-1)%(k);
            ++days;
            if (ind >= n)
                continue;
            count += coins[ind];      
        }
        if (count >= c) {
            l=k;
        }
        else {
            r=k-1;
        }
    }
    if (d*coins[0] < c) {
        cout << "Impossible\n";
        return;
    }
    if (l==d+1) {
        cout << "Infinity\n";
    }
    else 
        cout << l-1 << "\n";
}

signed main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    int t; cin >> t;
    while (t--) {
        solve();
    }
}