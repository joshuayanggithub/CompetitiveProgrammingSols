#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,sum,target;
const int maxN = 2e5+1;
vector<int> adj[maxN];
vector<int> hay(maxN);
bool vis[maxN];
vector<pair<int,int>> dir[maxN]; //directed tree

void dfs(int node, int prev) {
    vis[node] = true;
    for (auto& next: adj[node]) {
        if (!vis[next]) {
            dfs(next,node);
        }
    }
    //find the leaf nodes and recursive backtrack up 
    int diff = abs(target-hay[node]);
    //if node less than target, then it gets stuff, otherwise it gives away stuff
    //create directed new tree
    if (hay[node] < target) {
        dir[prev].push_back({node,diff});
        hay[prev] -= diff;
    }   
    else if (hay[node] > target) {
        dir[node].push_back({prev,diff});
        hay[prev] += diff;
    }
}
signed main() {
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> hay[i];
        sum += hay[i];
    }
    target = sum/n; //should be whole number
    for (int i=1; i<n; ++i) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //root any arbitary node
    //find the leaf nodes and recursive backtrack up 
    dfs(1, 0);
    //find nodes without any arrows pointing TO/INSIDE it, store inside data structure
    queue<int> q;
    vector<int> inside(n+1);
    for (int i=1; i<=n; ++i) {
        for (auto& next: dir[i]) {
            inside[next.first]++;
        }
    }
    for (int i=1; i<=n; ++i) {
        if (inside[i] == 0) {
            q.push(i);
        }
    }
    vector<array<int,3>> ans;
    //loop through structure, while adding new nodes
    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (auto& next: dir[node]) {
            int neighbor = next.first; int give = next.second;
            ans.push_back({node,neighbor,give});
            inside[neighbor]--;
            if (inside[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i=0; i<ans.size(); ++i) {
        cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << "\n";
    }
}