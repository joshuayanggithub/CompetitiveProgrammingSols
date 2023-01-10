#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k,health;
//int slimes[(int)2e5+1];

void solve() {
    cin >> n >> k;
    vector<int> v1;
    vector<int> v2;
    for (int i=1; i<=k-1; ++i) {
        int a; cin >>a;
        v1.push_back(a);
    }
    cin >> health;
    reverse(v1.begin(),v1.end());
    for (int i=k+1; i<=n; ++i) {
        int a; cin >> a;
        v2.push_back(a);
    }
    int min1=health,min2=health;
    int cur1=0,cur2=0;
    for (int i=0; i<v1.size(); ++i) {
        cur1 += v1[i]; min1 = min(min1, cur1);
    }
    for (int i=0; i<v2.size(); ++i) {
        cur2 += v2[i]; min2 = min(min2, cur2);
    }
    int temp = health;
    if (health + min1 >= 0 || health + min2 >= 0) {
        cout << "YES\n"; return;
    }
    for (int i=0; i<v1.size(); ++i) {
        temp += v1[i];
        if (temp + min2 >= 0) {
            cout << "YES\n"; return;
        }
    }
    temp = health;
    for (int i=0; i<v2.size(); ++i) {
        temp += v2[i];
        if (temp + min1 >= 0) {
            cout << "YES\n"; return;
        }
    }
    cout << "NO\n";
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