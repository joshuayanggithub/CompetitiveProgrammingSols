#include <bits/stdc++.h>
using namespace std;
#define f first
#define w second

int n,m;
const int mxN = 1e5+1;
vector<pair<int,int>> adj[mxN];
int map_[mxN];
int vis[mxN];

void dfs(int node,int minw, int cc) {
    vis[node] = cc;
    for (auto& next: adj[node]) {
        if (vis[next.f] || next.w < minw)
            continue;
        dfs(next.f, minw, cc);
    }
}

bool calc_dfs(int minw) {
    int cc = 1;
    for (int node=1; node<=n; ++node) {
        if (vis[node]) {
            continue;
        }
        dfs(node, minw, cc);
        ++cc;
    }
    for (int node=1; node<=n; ++node) {
        if (vis[node] != vis[map_[node]])
            return false; //they have to be same connected component
    }
    return true;
}

int main() {
    freopen("wormsort.in","r",stdin);
    freopen("wormsort.out","w",stdout);
    cin >> n >> m;
    int temp;
    //set<int> possiblew;
    for (int i=1; i<=n; ++i) {
        cin >> temp;
        map_[temp] = i; //node "temp" is in position "i" and needs to go to position "temp"
    }
    for (int i=0; i<m; ++i) {
        int a,b,c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
        //possiblew.insert(c);
    }
    
    int l = 0; 
    int r = 1e9+1; 
    int minw;
    
    while (l<r) {
        minw = (l+r+1)/2;
        if (l==r)
            break;
        if (!calc_dfs(minw)) {
            r = minw-1;
        }
        else {
            l = minw;
        }
        memset(vis,0,sizeof(vis));
    }
    if (l == 1e9+1)
        cout << -1;
    else
        cout << l;
}