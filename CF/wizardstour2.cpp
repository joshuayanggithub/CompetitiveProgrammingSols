#include <bits/stdc++.h>
using namespace std;

//editorial solved

const int maxn = 200001;
int n,m;
vector<int> adj[maxn];
bool vis[maxn];
vector<tuple<int,int,int>> ret;

int dfs(int node, int parent) {
    vis[node] = true;
    vector<int> children;
    for (auto next: adj[node]) {
        if (next == parent) continue;
        if (vis[next] && next > node) { //this means you have a cycle, not an edge in spanning tree
            //you cannot count the same edge twice, so you need a one-time condition
            children.push_back(next); //to signify this edge is a child of this node 
        }
        else if (!vis[next]) {
            if (dfs(next,node) == 1) {
                children.push_back(next);
            }
        }
    }
    for (int i=0; i<children.size(); i+=2) {
        if (i+1 >= children.size()) {
            break;
        }
        ret.push_back({children[i],node,children[i+1]});
    }
    if (children.size()%2 == 0) return 1; // the edge between node and parent is free
    else if (children.size()%2 == 1 && parent != 0) {
        ret.push_back({children[children.size()-1],node,parent});
    }
    return 0; //there is no free edge because the one left over edge needs to be paired with the nod-parent edge of this dfs
}
int main() {
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=1; i<=n; ++i) {
        if (vis[i]) continue;
        dfs(i,0);
    }
    cout << ret.size() << "\n";
    for (int i=0; i<ret.size(); ++i) {
        cout << get<0>(ret[i]) << " " << get<1>(ret[i]) << " " << get<2>(ret[i]) << "\n";
    }
 }