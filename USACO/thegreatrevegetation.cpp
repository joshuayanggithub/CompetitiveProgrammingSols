#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5+1;
int n,m;
vector<pair<int,int>> adj[mxN];
bool works = true;
int vis[mxN];

void dfs(int node, int c) {
    vis[node] = c;
    for (auto& next: adj[node]) {
        int nextc;
        if (next.second == 1) { //same or diff color
            nextc = c;
        }
        else {
            nextc = -c;
        }
        if (vis[next.first] != 0) {
            if (nextc != vis[next.first]) {
                works = false;
            }
            continue;
        }
        dfs(next.first, nextc);
    }
}
void start_dfs() {
    int cc = 0;
    for (int i=1; i<=n; ++i) {
        if (vis[i])
            continue;
        ++cc;
        dfs(i,1);
    }
    if (works)
        cout << "1";
    else {
        cout << "0";
        return;
    }
    for (int i=1; i<=cc; ++i) {
        cout << "0";
    }
}
int main() {
    freopen("revegetate.in","r",stdin);
    freopen("revegetate.out","w",stdout);
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        char a; int b, c;
        cin >> a >> b >> c;
        int d = 1; //same or diff 1 or -1
        if (a == 'D') {
            d = -1;
        }
        adj[b].push_back({c,d});
        adj[c].push_back({b,d});
    }
    start_dfs();
}

/*
3 2
S 1 2
D 3 2
*/