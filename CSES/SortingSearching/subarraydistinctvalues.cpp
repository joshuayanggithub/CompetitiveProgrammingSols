#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n,k; cin >> n >> k;
    vector<int> v(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> v[i];
    }
    ll cur=0,l=1,r=0,ans =0;
    map<int,int> m;
    for (;l<=n && r<=n; ++l) {
        while (r+1<=n && (m.size() < k || (m.size() == k && m.count(v[r+1])) )) {
            ++r;
            m[v[r]] = r;
            ++cur;
        }
        ans += cur;
        cur--;
        if (m[v[l]] == l) {
            m.erase(v[l]);
        }
    }
    cout << ans;
}