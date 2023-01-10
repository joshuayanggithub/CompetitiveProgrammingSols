#include <bits/stdc++.h>
using namespace std;


const int MAXN = 402;
int dp[MAXN][MAXN];
int main() {
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    int n,k;
    cin >> n >> k;
    //int dp[n+1][k+1][n+1];
    k+= 1;
    int groups[n+1];
    int sum = 0;
    for (int i=1; i<=n; ++i) {
        cin >> groups[i];
        sum += groups[i];
    }
    for (int i=0; i<=n; ++i) {
        for (int s=0; s<=k; ++s) {
            dp[i][s] = 4e8+1;
        }
    }
    dp[0][0] = 0;
    for (int i=0; i<n; ++i) {
        for (int s=0; s<k; ++s) {
            int ma =groups[i+1];
            for (int j=i; j>=0; --j) {
                ma = max(groups[j+1],ma);
                dp[i+1][s+1] = min(dp[j][s] + ma*(i-j+1), dp[i+1][s+1]);
            }
        }
    }
    int ans = dp[n][0];
    for (int s=0; s<=k; ++s) {
        ans = min(ans, dp[n][s]);
    }
    cout << ans - sum;
}   


/*
6 2
7 9 8 2 3 2
*/