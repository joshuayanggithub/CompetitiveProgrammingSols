#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second

const int maxn = 200001;
int n,m;
vector<int> adj[maxn];
int degree[maxn];
map<pair<int,int>,bool> vis;
queue<pair<int,int>> cur;

void dfs(int node, int before) {
    vis[{min(node,before),max(node,before)}] = true;
    while (cur.size() >= 2) {
        pair<int,int> p1 = cur.front(); cur.pop();
        pair<int,int> p2 = cur.front(); cur.pop();
        int incommon;
        if (p1.a == p2.a) {
            incommon = p1.a;
        }
        else if(p1.b == p2.a || p1.b == p2.b) {
            incommon = p2.b;
        }
    }
    if (degree[node] == 1) { //leaf
        cur.push({node,before});
        degree[node]--;
        degree[before]--;
    }
    for (auto next: adj[node]) {
        if (!vis[{min(node,next),max(node,next)}]) {
            dfs(next, node);
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        vis[{min(a,b),max(a,b)}] = false;
    }
    for (int i=1; i<=n; ++i) {
        degree[i] = adj[i].size();
    }
    for (int i=1; i<=n; ++i) {
        for (int j=0; j<adj[i].size(); ++j) {
            pair<int,int> edge = { min(i,adj[i][j]) , max(i,adj[i][j]) };
            if (!vis[edge]) {
                dfs(i,adj[i][j]);
            }
        }
    }
}