#include <bits/stdc++.h>
using namespace std;

struct worm {
    int a,b,w;
};
bool comp(const worm& w1, const worm& w2) {
    return w1.w > w2.w;
}

const int maxn = 100001;
int a[maxn];
worm holes[maxn];
int n,m;

bool valid(int x) {
    vector<int> adj[maxn];
    vector<int> vis (maxn);
    stack<int> stk;
    for (int i=0; i<=x; ++i) {
        adj[holes[i].a].push_back(holes[i].b);
        adj[holes[i].b].push_back(holes[i].a);
    }
    int groupnum = 1;
    for (int i=1; i<=n; ++i) {
        if (vis[i] != 0) {
            continue;
        }
        stk.push(i);
        vis[i] = groupnum;
        while (!stk.empty()) {
            int node = stk.top(); stk.pop();
            vis[node] = groupnum;
            for (auto next: adj[node]) {
                if (vis[next] == 0) {
                    stk.push(next);
                    vis[next] = groupnum;
                }
            }
        }
        ++groupnum;
    }
    for (int i=1; i<=n; ++i) {
        if (vis[a[i]] != vis[i]) {
            return false;
        }
    }
    return true;
}
int main() {
    freopen("wormsort.in","r",stdin);
    freopen("wormsort.out","w",stdout);
    
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
    }
    for (int i=0; i<m; ++i) {
        cin >> holes[i].a >> holes[i].b >> holes[i].w;
    }
    sort(holes,holes+maxn,comp);
    int l = 0;
    int r = m-1;
    bool neg1 = true;
    for (int i=1; i<=n; ++i) {
        if (a[i] != i) {
            neg1 = false;
            break;
        }
    }
    while (l<r) {
        int mid = (l+r-1)/2;
        if (valid(mid)) {
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    if (neg1)
        cout << -1;   
    else 
        cout << holes[r].w;
}