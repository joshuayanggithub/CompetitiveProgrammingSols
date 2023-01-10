#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second

const int maxn = 1001, maxm = 1001;
int dp[maxn][maxm][2];

int dis(pair<int,int> c1, pair<int,int> c2) {
    return abs(c1.x - c2.x)*abs(c1.x - c2.x) + abs(c1.y - c2.y)*abs(c1.y - c2.y);
}
int main() {
    freopen("checklist.in","r",stdin);
    freopen("checklist.out","w",stdout);
    int n,m; cin >> n >> m;
    pair<int,int> h[n+1];
    pair<int,int> g[m+1];
    for (int i=1; i<=n; ++i) {
        cin >> h[i].x >> h[i].y;
    }
    h[0] = h[1];
    for (int i=1; i<=m; ++i) {
        cin >> g[i].x >> g[i].y;
    }
    g[0] = g[1];
    //cannot access dp[0][c] where c is number >=1 or dp[1][1][0]
    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=m; ++j) {
            dp[i][j][0] = INT_MAX;
            dp[i][j][1] = INT_MAX;
        }
    }
    dp[0][0][0] = 0;
    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=m; ++j) {
            if ( !(i == 0 && j >0) && i!=n  ) {
                if (dp[i][j][0] != INT_MAX)
                    dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][0] + dis(h[i+1],h[i])); //dis(h[1],h[0]) should be 0
                if (j!= 0 && dp[i][j][1] != INT_MAX)
                    dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][1] + dis(h[i+1],g[j])); //j = 0
            }
            if (i!=0 && j!=m ) {
                if (dp[i][j][0] != INT_MAX)
                    dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][0] + dis(g[j+1], h[i]) );
                if (j != 0 && dp[i][j][1] != INT_MAX)
                    dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][1] + dis(g[j+1], g[j]) );
            }
        }
    }
    cout << dp[n][m][0];
}
/*
3 2
0 0
1 0
2 0
0 3
1 3
*/