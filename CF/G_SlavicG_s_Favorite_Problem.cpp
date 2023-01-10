#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+1;
vector<pair<int,int>> adj[mxN];
set<int> values1,values2;
int n,a,b;

void dfs(int node, int prev, int value,int way) {
    if (way == 1) {
        if (node == b) return; //game rules is dont go past b
        values1.insert(value);
    }
    else {
        if (node !=b) values2.insert(value);
    } 
    for (auto& [next,weight]: adj[node]) {
        if (next == prev)
            continue;
        dfs(next,node,(value ^ weight),way);
    }
}

void solve() {
    cin >> n >> a >> b;
    for (int i=1; i<n; ++i) {
        int u,v,w; cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(a,-1,0,1);
    dfs(b,-1,0,2);
    bool works = false;
    for (auto& next: values1) {
        if (values2.count(next)) {
            works = true; 
            break;
        }
    }
    cout << (works ? "YES" : "NO") << "\n"; 
    for (int i=1; i<=n; ++i) {
        adj[i].clear();
    }
    values1.clear();
    values2.clear();
} 

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}