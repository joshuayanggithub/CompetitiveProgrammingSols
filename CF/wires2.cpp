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
        //set<pair<int,int>> contained;
        for (int i=1; i<=n; ++i) {
            int a = coordcompress[wires[i].first];
            int b = coordcompress[wires[i].second];
            adj[a].push_back({b,i});
            adj[b].push_back({a,i});
        }
        stack<int> stack;
        vector<pair<int,pair<int,int>>> connectedcomponents;
        vector<bool> vis (numpoints+1,0);
        for (auto a: points) {
            int node = coordcompress[a];
            if (vis[node]) {
                continue;
            }
            else {
                stack.push(node);
            }
            int lastwire = adj[node][0].second;
            int lastnode = node;
            while (!stack.empty()) {
                int next = stack.top(); stack.pop();
                vis[next] = true;
                for (auto neighbor: adj[next]) {
                    if (!vis[neighbor.first]) {
                        vis[neighbor.first] = true;
                        stack.push(neighbor.first);
                        lastwire = neighbor.second;
                        lastnode = neighbor.first;
                    }
                }
            }
            connectedcomponents.push_back({lastwire, {node,lastnode}}); //wirenum
        }
        cout << connectedcomponents.size()-1 << "\n";
        for (int i=0; i<connectedcomponents.size()-1; ++i) {
            int lastwire = connectedcomponents[i].first;
            int parent = connectedcomponents[i+1].second.first;
            int lastnode = connectedcomponents[i].second.second;
            cout << lastwire << " " << reverse[lastnode] << " " << reverse[parent] << "\n";
        }
    }
}