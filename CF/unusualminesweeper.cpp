#include <bits/stdc++.h>
using namespace std;

struct Mine {
    int x,y,t,i;
};
bool sortx(const Mine& m1, const Mine& m2) {
    if (m1.x == m2.x) {
        return m1.y < m2.y;
    }
    return m1.x < m2.x;
}
bool sorty(const Mine& m1, const Mine& m2) {
    if (m1.y == m2.y) {
        return m1.x < m2.x;
    }
    return m1.y < m2.y;
}
bool sorti(const Mine& m1, const Mine& m2) {
    return m1.i < m2.i;
}
int main() {
    int t;
    cin >> t;
    for (int j=0; j<t; ++j) {
        int n,k;
        cin >> n >> k;
        Mine grid[n];
        for (int i=0; i<n; ++i) {
            cin >> grid[i].x >> grid[i].y >> grid[i].t;
            grid[i].i = i;
        }
        //sort by x value
        sort(grid,grid+n,sortx);
        int l = 0;
        int r =1;
        vector<int> adj[n];
        while (l<n && r<n) {
            if (grid[l].x == grid[r].x && grid[r].y - grid[l].y <= k) {
                adj[grid[l].i].push_back(grid[r].i);
                adj[grid[r].i].push_back(grid[l].i);
                ++r;
            }
            else {
                l = max(l+1,r-1);
            }
            if (l == r) {
                ++r;
            }
        } 
        //sort by y value
        sort(grid,grid+n,sorty);
        l = 0;
        r =1;
        while (l<n && r<n) {
            if (grid[l].y == grid[r].y && grid[r].x - grid[l].x <= k) {
                adj[grid[l].i].push_back(grid[r].i);
                adj[grid[r].i].push_back(grid[l].i);
                ++r;
            }
            else {
                l = max(l+1,r-1);
            }
            if (l == r) {
                ++r;
            }
        } 
        //dfs all connected components
        vector<bool> vis (n);
        stack<int> stack;
        vector<int> compstart;
        sort(grid,grid+n,sorti);
        for (int i=0; i<n; ++i) {
            int mi = INT_MAX;
            if (!vis[i]) {
                stack.push(i);
                while (!stack.empty()) {
                    int node = stack.top(); stack.pop();
                    mi = min(mi, grid[node].t);
                    vis[node] = true;
                    for (int next: adj[node]) {
                        if (!vis[next]) {
                            stack.push(next);
                            vis[next] = true;
                        }
                    }
                }
                compstart.push_back(mi);
            }
        }
        sort(compstart.rbegin(),compstart.rend());
        for (int i=0; i<compstart.size(); ++i) {
            if (i >= compstart[i]) {
                cout << max(i-1,compstart[i]) << "\n";
                break;
            }
            else if(i == compstart.size()-1) {
                cout << i << "\n";
            }
        }
    }
    
}