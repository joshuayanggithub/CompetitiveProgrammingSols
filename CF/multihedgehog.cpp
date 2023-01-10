#include <bits/stdc++.h>
using namespace std;

const int maxn = 9;
vector<int> adj[maxn];
vector<int> deg1;
vector<int> numhedgehog;
int degree[maxn];
int newdegree[maxn];
bool vis[maxn];

void dfs(int node) { //more like bfs one step
    vis[node] = true;
    for (auto next: adj[node]) {
        if (!vis[next]) {
            vis[next] = true;
            deg1.push_back(next);
        }
        --newdegree[next]; //signify we been here
    }
}
int main() {
    int n,k;
    cin >> n >> k;
    for (int i=0; i<n-1; ++i) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++degree[a];
        ++newdegree[a];
        ++degree[b];
        ++newdegree[b];
    }
    for (int i=1; i<=n; ++i) {
        if (degree[i] == 1) {
            deg1.push_back(i);
        }
    }
    int hedge = 1;
    int newind = 0;
    bool isHedge = true;
    while (hedge <= min(k+1,n)) {
        int oldsize = deg1.size();
        for (int i=newind; i<oldsize; ++i) {
            dfs(deg1[i]);
        }
        newind = oldsize;
        for (int i=newind; i<deg1.size(); ++i) {
            int node = deg1[i];
            if (hedge != k) {
                if (degree[node] <= 3) {
                    isHedge = false;
                    break;
                }
                if (newdegree[node] != 1) {
                    isHedge = false;
                    break;
                }
            }
            else if (hedge == k) {
                if (degree[node] < 3) {
                    isHedge = false;
                    break;
                }
                if (newdegree[node] != 0) {
                    isHedge = false;
                    break;
                }
            }
        }
        ++hedge;
    }
    int notvis = 0;
    for (int i=1; i<=n; ++i) {
        if (!vis[i]) {
            ++notvis;
        }
    }
    if (isHedge && notvis == 0) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
}