#include <bits/stdc++.h>
using namespace std;


int t,n;
const int MAXN = 2*(1e5) + 3;
int dp[MAXN][2];

void solve() {
    bool a[n+1];
    dp[0][0] = dp[0][1] = 200001;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        dp[i][0] = dp[i][1] = 200001;
    }
    // 0 you 1 friend
    dp[0][0] = 0;
    for (int i=0; i<=n; ++i) {
        dp[i+1][1] = min(dp[i][0] + (a[i+1] == 1), dp[i+1][1]);
        dp[i+2][1] = min(dp[i][0] + (a[i+2] == 1) + (a[i+1] == 1) , dp[i+2][1]);
        dp[i+2][0] = min(dp[i][1], dp[i+2][0]);
        dp[i+1][0] = min(dp[i][1], dp[i+1][0]);
    }
    cout << min(dp[n][0], dp[n][1]) << "\n";
}
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        solve();
    }
}


/*
6
8
1 0 1 1 0 1 1 1
5
1 1 1 1 0
7
1 1 1 1 0 0 1
6
1 1 1 1 1 1
1
1
1
0
*/