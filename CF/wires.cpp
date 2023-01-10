#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int j=0; j<t; ++j) {
        int n;
        cin >> n;
        set<int> points;
        pair<int,int> wires[n+1];
        unordered_map<int,int> coordcompress;
        unordered_map<int,int> reverse;
        for (int i=1; i<=n; ++i) {
            int a,b;
            cin >> a >> b;
            points.insert(a); points.insert(b);
            wires[i] = {a,b};
        }
        int counter = 1;
        int numpoints = points.size();
        for (auto a: points) {
            coordcompress.insert({a, counter});
            reverse.insert({counter,a});
            ++counter;
        }
        vector<pair<int,int>> adj[numpoints+1];
        for (int i=1; i<=n; ++i) {
            int a = coordcompress[wires[i].first];
            int b = coordcompress[wires[i].second];
            adj[a].push_back({b,i});
            adj[b].push_back({a,i});
        }
        stack<int> stack;
        vector<pair<int,int>> connectedcomponents;
        vector<bool> vis (numpoints+1);
        for (auto a: points) {
            int node = coordcompress[a];
            if (vis[node]) {
                continue;
            }
            stack.push(node);
            pair<int,int> lowestneighbor = {0,INT_MAX};
            while (!stack.empty()) {
                int next = stack.top(); stack.pop();
                if (adj[next].size() < lowestneighbor.second) {
                    lowestneighbor.first = next;
                    lowestneighbor.second = adj[next].size();
                }
                vis[next] = true;
                for (auto neighbor: adj[next]) {
                    if (!vis[neighbor.first]) {
                        stack.push(neighbor.first);
                    }
                }
            }
            connectedcomponents.push_back({adj[lowestneighbor.first][0].second, lowestneighbor.first}); //wirenum
        }
        cout << connectedcomponents.size()-1 << "\n";
        for (int i=0; i<connectedcomponents.size()-1; ++i) {
            int wirenum = connectedcomponents[i].first;
            int wirenum2 = connectedcomponents[i+1].first;
            cout << wirenum << " " << reverse[connectedcomponents[i].second] << " " << wires[wirenum2].first << "\n";
        }
    }
}