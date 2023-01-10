#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> adj[n+1];
    int a,b;
    for (int i=0; i<n-1; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis (n+1);
    vector<int> colors(n+1);
    queue<int> q;
    queue<int> c;
    q.push(1);
    c.push(0);
    long long red = 0;
    long long blue = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        int color = c.front(); c.pop();
        colors[node] = color;
        if (color == 0) {
            ++red;
        }
        else {
            ++blue;
        }
        vis[node] = true;
        for (int next: adj[node]) {
            if (!vis[next]) {
                vis[next] = true;
                q.push(next);
                c.push((color+1)%2);
            }
        }
    }
    long long ans =0;
    for (int i=1; i<=n; ++i) {
        if (colors[i] == 0) {
            ans += ( (long long) blue - adj[i].size());
        }
        else {
            ans += ((long long) red - adj[i].size());
        }
    }
    ans /= 2;
    cout << ans;
}