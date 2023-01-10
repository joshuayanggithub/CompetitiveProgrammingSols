#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+1;
int t, n;
vector<array<int,3>> adj[mxN];
pair<int,int> ans[mxN];
vector<int>v;

void dfs(int prev, int node, int sum1, int length, int ptr, int sum2) {
    for (auto& nextp: adj[node]) {
        int next = nextp[0];
        int a = nextp[1];
        int b = nextp[2];
        int nextptr = ptr;
        int nextsum = sum2;
        v.push_back(b);
        while (nextptr+1 < v.size() && sum1+a >= nextsum + v[nextptr+1]) {
            ++nextptr;
            nextsum += v[nextptr];
            ++length;
        }
        ans[next] = {-1,nextptr+1};
        dfs(node, next, sum1+a, length+1, nextptr, nextsum);
        v.pop_back();
    }
}
void solve() {
    cin >> n;
    for (int i=2; i<=n; ++i) {
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({i,b,c});
    }
    dfs(-1,1,0,0,-1,0);
    for (int i=2; i<=n; ++i) {
        cout << ans[i].second << " ";
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