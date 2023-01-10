#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,k;

void solve() {
    cin >> n >> k;
    vector<pair<ll, ll>> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i].second;
        a[i].first = a[i].second%k;
    }
    sort(a.begin(),a.end());
    int l=0, r=a.size()-1;
    long long ans = 0;
    vector<int> skipped;
    while (l<r) {
        if (a[l].first + a[r].first >=k) {
            ans += (a[l].second + a[r].second)/k;
            ++l; --r;
        }
        else {
            skipped.push_back(l);
            ++l;
        }
    }
    if (l==r) { //edge case
        skipped.push_back(l);
    }
    for (int i=0; i<skipped.size(); i+=2) {
        ans += (a[skipped[i]].second + a[skipped[i+1]].second)/k;
    }
    cout << ans << "\n";
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