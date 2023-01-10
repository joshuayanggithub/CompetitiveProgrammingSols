#include <bits/stdc++.h>
using namespace std;

const int mxN = 501; 
vector<int> adj[mxN];
//int cyclic[mxN][mxN];
int original; //og node
bool vis[mxN];
bool returns[mxN]; //wehther it returns to original
set<int> cyclic;

void dfs(int node, int prev) {
    vis[node] = true;
    for (auto next: adj[node]) {
        if (returns[next]) {
            returns[node] = true;
            cyclic.insert(node);
            continue;
        }
        if (vis[next]) {
            if (next == original) {
                returns[node] = true;
                returns[next] = true;
                cyclic.insert(node);
            }
            continue;
        }
        dfs(next, node);
        if (returns[next]) {
            returns[node] = true;
            cyclic.insert(node);
        }
    }
    //vis[node] = false; //reset?
}

int main() {
    //freopen("text.in","r",stdin);
   // freopen("text.out","w",stdout);
    int n; cin >> n;
    for (int i=1; i<=n; ++i) {
        vector<int> v(n);
        for (int j=0; j<n; ++j) {
            cin >> v[j];
        }
        for (int j=0; j<n; ++j) {
            if (v[j] == i) {
                break;
            }
            adj[i].push_back(v[j]);
        }
    }

    for (int node=1; node<=n; ++node) {
        original = node;
        dfs(original, -1);
        for (auto next: adj[node]) {
            if (cyclic.count(next) == 1) {
                cout << next << "\n";
                break;
            }
        }
       //cout << "hi";
        if (!cyclic.size())
            cout << original << "\n";
        cyclic.clear();
        memset(returns, 0,sizeof(returns));
        memset(vis, 0,sizeof(vis));
    }

}
