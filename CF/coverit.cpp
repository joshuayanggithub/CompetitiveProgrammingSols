#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int main() {
    int t;
    cin >> t;
    for (int j=0; j<t; ++j) {
        int n,m;
        cin >> n >> m;
        vector<int> adj[n+1];
        vector<bool> vis (n+1);
        for (int i=0; i<m; ++i) {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<pair<int,int>> q;
        q.push({1,0});
        vector<int> c1;
        vector<int> c2;
        while (!q.empty()) {
            int node = q.front().f; 
            int color = q.front().s;
            if (color == 0) {
                c1.push_back(node);
            }
            else {
                c2.push_back(node);
            }
            q.pop();
            vis[node] = true;
            for (int next: adj[node]) {
                if (!vis[next]) {
                    vis[next] = true;
                    q.push({next,(color+1)%2});
                }
            }
        }
        if (c1.size()<c2.size()) {
            cout << c1.size() << "\n";
            for (int i=0; i<c1.size(); ++i) {
                cout << c1[i] << " ";
            }
        }
        else {
            cout << c2.size() << "\n";
            for (int i=0; i<c2.size(); ++i) {
                cout << c2[i] << " ";
            }
        }
    }
}