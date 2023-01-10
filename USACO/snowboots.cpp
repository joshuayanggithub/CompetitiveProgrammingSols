#include <bits/stdc++.h>
using namespace std;
const int maxn = 250;
int n,b;
int path[maxn];
pair<int,int> boots[maxn];
int ans = INT_MAX;
bool vis[maxn][maxn];

void dfs(int pos, int bind) {
    if (vis[pos][bind]) {
        return;
    }
    vis[pos][bind] = true;
    if (bind == b || boots[bind].first < path[pos] ) {
        return;
    }
    if (pos == n-1) {
        ans = min(ans,bind);
        return;
    }
    for (int i=pos+1; i<=min(n-1,pos+boots[bind].second); ++i) {
        if (boots[bind].first >= path[i]) {
            dfs(i,bind);
        }
    }
    for (int i=bind+1; i<b; ++i) {
        dfs(pos,i);
    }
    
    //dfs(pos,bind+1);
}
int main() {
    freopen("snowboots.in","r",stdin);
    freopen("snowboots.out","w",stdout);

    cin >> n >> b;
    for (int i=0; i<n; ++i){
        cin >> path[i];
    }
    for (int i=0; i<b; ++i) {
        cin >> boots[i].first >> boots[i].second;
    }
    dfs(0,0);
    cout << ans;
}