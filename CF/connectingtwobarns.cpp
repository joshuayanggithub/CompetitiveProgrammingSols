#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int j=0; j<t; ++j) {
        int n,m;
        cin >> n >> m;
        vector<int> adj[n+1];
        vector<bool> vis (n+1);
        stack<int> stack;
        for (int i=0; i<m; ++i) {
            int a,b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool onensame = false;
        //components 1 and n
        vector<int> compone;
        vector<int> compn;
        stack.push(1);
        while (!stack.empty()) {
            int node = stack.top(); stack.pop();
            compone.push_back(node);
            vis[node] = true;
            if (node == n) {
                onensame = true;
            }
            for (int next: adj[node]) {
                if (!vis[next]) {
                    vis[next] = true;
                    stack.push(next);
                }
            }
        }
        stack.push(n);
        while (!stack.empty()) {
            int node = stack.top(); stack.pop();
            compn.push_back(node);
            vis[node] = true;
            for (int next: adj[node]) {
                if (!vis[next]) {
                    vis[next] = true;
                    stack.push(next);
                }
            }
        }
        int safedist = 10e5+1;
        compone.push_back(-safedist);
        compn.push_back(-safedist);
        compone.push_back(safedist);
        compn.push_back(safedist);
        sort(compone.begin(), compone.end());
        sort(compn.begin(), compn.end());
        //calculate shortest dist
        vector<int> shortestdistone (n+1, INT_MAX);
        int field = 1;
        int l = 0;
        int r = 1;
        while (field <= n) {
            shortestdistone[field] = min(shortestdistone[field], min( abs(field-compone[l]), abs(compone[r]-field)) );
            if (field >= compone[l] && field <= compone[r]) {
                ++field;
            }
            else { //way greater
                l = min(l+1,(int) compone.size()-2);
                r = min(r+1,(int) compone.size()-1);
            }
        }
        vector<int> shortestdistn (n+1, INT_MAX);
        field = 1;
        l = 0;
        r = 1;
        while (field <= n) {
            shortestdistn[field] = min(shortestdistn[field], min( abs(field-compn[l]), abs(compn[r]-field)) );
            if (field >= compn[l] && field <= compn[r]) {
                ++field;
            }
            else { //way greater
                l = min(l+1,(int) compn.size()-2);
                r = min(r+1,(int) compn.size()-1);
            }
        }
        long long ans =__LONG_LONG_MAX__;
        for (int i: compn) {
            if (i>=0 && i<=n) {
                vis[i] = false;
            }
        }
        for (int i: compone) {
            if (i>=0 && i<=n) {
                vis[i] = false;
            }
        }
        for (int i=1; i<=n; ++i) {
            if (vis[i]) {
                continue;
            }
            stack.push(i);
            int mindistone = INT_MAX; //of connected component
            int mindistn = INT_MAX; //of connected component
            while (!stack.empty()) {
                int node = stack.top(); stack.pop();
                vis[node] = true;
                mindistone = min(mindistone, shortestdistone[node]);
                mindistn = min(mindistn, shortestdistn[node]);
                for (int next: adj[node]) {
                    if (!vis[next]) {
                        vis[next] = true;
                        stack.push(next);
                    }
                }
            }
            if (!onensame) {
                ans = min(ans, (long long) mindistone*mindistone + (long long) mindistn * mindistn);
            }
        }
        if (onensame) {
            ans = 0;
        }
        cout << ans << "\n";
    }
}