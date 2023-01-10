#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mxN = 2e5+1;
int t, n;
vector<array<int,3>> adj[mxN];
int ans[mxN];
vector<ll>v;

void dfs(int node, ll sum1, ll sum2) {
    for (auto& nextp: adj[node]) {
        int next = nextp[0];
        int a = nextp[1];
        int b = nextp[2];
        ll nextsum = b+sum2;
        v.push_back(nextsum);
        auto it = upper_bound(v.begin(),v.end(), sum1+a);
        int ind = it - v.begin()+1;
        ans[next] = ind-1;
        dfs(next, sum1+a, nextsum);
        v.pop_back();
    }
}
void solve() {
    cin >> n;
    for (int i=2; i<=n; ++i) {
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({i,b,c});
    }
    dfs(1,0,0);
    for (int i=2; i<=n; ++i) {
        cout << ans[i] << " ";
    }
    for (int i=1; i<=n; ++i){
        adj[i].clear();
    }
    cout << "\n";
    v.clear();
}
int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif

    cin >> t;
    while(t--) {
        solve();
    }
}