#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN =2e5+1;
int t,n;
vector<int> adj[mxN];
vector<pair<ll,ll>> bounds(mxN);
vector<int> cur(mxN);
int ans;

ll dfs(int prev, int node) {
    ll sum = 0;
    for (auto& next: adj[node]) {
        sum += dfs(node, next);
    }
    if (sum >= bounds[node].first) { //leafs included
        return min(sum,bounds[node].second);
    }
    else {
        ++ans;
        return bounds[node].second;
    }
}
void solve() {
    cin >> n;
    for (int i=2; i<=n; ++i) {
        int a; cin >> a;
        adj[a].push_back(i);
    }
    for (int i=1; i<=n; ++i) {
        cin >> bounds[i].first >> bounds[i].second;
    }
    auto temp = dfs(0,1);
    cout << ans << "\n";
}
int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    cin >> t;
    while (t--) {
        solve();
        ans=0; //reset
        for (int i=1; i<=n; ++i) {
            adj[i].clear();
        }
    }
}