#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> adj[n+1];
    queue<pair<int,int>> deg1;
    vector<int> degree (n+1);
    vector<bool> vis (n+1);
    for (int i=0; i<n-1; ++i) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        ++degree[a];
        ++degree[b];
    }
    for (int i=1; i<=n; ++i) {
        if (degree[i] == 1) {
            deg1.push({i,0});
        }
    }
    bool works = true;
    while (!deg1.empty()) {
        int node = deg1.front().f; 
        int kvalue = deg1.front().s;
        deg1.pop();
        vis[node] = true;
        if ( (degree[node] != 1 && kvalue <k) || (degree[node] != 0 && kvalue == k) ) {
            works = false;
        }
        for (auto next: adj[node]) {
            if (!vis[next]) {
                vis[next] = true;
                if ( (degree[next] <= 3 && kvalue +1 <k) || (degree[next] < 3 && kvalue + 1 == k)) {
                    works = false;
                }
                deg1.push({next,kvalue+1});
            }
            --degree[next];
        }
        if (works == false) {
            break;
        }
    }
    if (works == true && n!= 1) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }

}