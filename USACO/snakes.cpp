#include <bits/stdc++.h>
using namespace std;


pair<int,int> dp[10][10];
int main() {
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    int n,k;
    cin >> n >> k;
    //int dp[n+1][k+1][n+1];
    k+= 1;
    int groups[n+1];
    for (int i=1; i<=n; ++i) {cin >> groups[i];}
    for (int i=0; i<=n; ++i) {
        for (int s=0; s<=k; ++s) {
            dp[i][s].first = 4e8+1;
        }
    }
    dp[0][0].first = 0;
    for (int i=0; i<n; ++i) {
        for (int next=1; next<=n; ++next) {
            for (int s=0; s<=k; ++s) {
                if (groups[next] < groups[i+1]) { //switched to
                    continue;
                }
                else if (groups[next] == dp[i][s].second) {
                    if (dp[i][s].first + dp[i][s].second - groups[i+1] < dp[i+1][s].first) {
                        dp[i+1][s].first = dp[i][s].first + dp[i][s].second - groups[i+1];
                        dp[i+1][s].second = dp[i][s].second;
                    }
                }
                else {
                    if (dp[i][s].first + groups[next] - groups[i+1] < dp[i+1][s+1].first) {
                        dp[i+1][s+1].first = dp[i][s].first + groups[next] - groups[i+1];
                        dp[i+1][s+1].second = groups[next];
                    }       
                }
            }
        }
    }
    int ans = dp[n][0].first;
    for (int s=0; s<=k; ++s) {
        ans = min(ans, dp[n][s].first);
    }
    cout << ans;
}   


/*
6 2
7 9 8 2 3 2
*/