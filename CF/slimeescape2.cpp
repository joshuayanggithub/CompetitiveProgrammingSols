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
    int cur1=0,cur2=0,p1=0,p2=0;
    while (p1<v1.size() && p2<v2.size()) {
        bool change = false;
        while (p1<v1.size() && (health + cur1 + v1[p1])>= 0) {
            cur1 += v1[p1];
            if (cur1 >=0) {
                health += cur1;
                cur1=0;
            }
            ++p1;
            change = true;
        }
        while (p2<v2.size() && (health + cur2 + v2[p2]) >= 0) {
            cur2 += v2[p2];
            if (cur2 >=0) {
                health += cur2;
                cur2=0;
            }
            ++p2;
            change = true;
        }
        if (change==false)
            break;
    }
    if (p1>=v1.size() || p2>=v2.size()) {
        cout <<"YES\n";
    }
    else {
        cout <<"NO\n";
    }
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