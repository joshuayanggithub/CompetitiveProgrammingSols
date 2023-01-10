#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int mxN = 1e5+1;
vector<pair<int,int>> adj[mxN];
int vis[mxN];
int leftout = 0;
ll num_moos = 0;
int backtrack = 0;

void dfs(int node, int cc) {
    vis[node] = cc;
    for (auto& next_node: adj[node]) { //there can only be one node leaving the current node anyways...
        int next = next_node.first;
        int weight = next_node.second;
        if (vis[next]) {
            if (vis[next] == cc) {
                backtrack = next; 
                leftout = weight;
            }
            return; //this should be the end of the function anyways;
        }
        dfs(next, cc);
        if (backtrack) {
            leftout = min(leftout, weight);
            if (node == backtrack) {
                backtrack = false; //so we dont consider weights that aren't part of the cycle
            }
            //return node;
        }
    }
}
void start_dfs() {
    int cc = 1;
    for (int cow=1; cow<=n; ++cow) {
        if (vis[cow]) {
            continue;
        }
        dfs(cow, cc);
        num_moos -= leftout;
        ++cc;
        //reset
        backtrack = false;
        leftout = 0;
    }
    cout << num_moos;
}
int main() {
    cin >> n;
    for (int i=1; i<=n; ++i) {
        int a,b; cin >> a >> b;
        adj[i].push_back({a,b});
        num_moos += b;
    }
    start_dfs();
}

/*
4
2 10
3 20
4 30
1 40
*/