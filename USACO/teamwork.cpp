#include <bits/stdc++.h>
using namespace std;

pair<int,int> dp[10001][1001];
int n,k;
int main() {
    freopen("teamwork.in","r",stdin);
    freopen("teamwork.out","w",stdout);
    cin >> n >> k;
    int cities[n+1];
    for (int i=1; i<=n; ++i) {cin >> cities[i];}
    for (int c=0; c<=n; ++c) {
        for (int g=0; g<=k; ++g) { //cows in this group!
            dp[c][g].first = (int) (-1e9)-1;
        }
    }
    dp[0][k].first = 0;
    for (int c=0; c<n; ++c) {
        for (int g=1; g<=k; ++g) { //cows in this group!
            if (g != k) {
                dp[c+1][g+1].second = max(dp[c][g].second, cities[c+1]);
                int extradd = 0;
                if (cities[c+1] > dp[c][g].second) {
                    extradd = (cities[c+1]-dp[c][g].second) * g; //make up for all the times we didnt add before
                }
                dp[c+1][g+1].first = max(dp[c][g].first + dp[c+1][g+1].second + extradd,dp[c+1][g+1].first);
            }
            dp[c+1][1].first = max(dp[c][g].first + cities[c+1],dp[c+1][1].first);
            dp[c+1][1].second = cities[c+1];
        }
    }
    int ans =0;
    for (int g=1; g<=k; ++g) {
        ans = max(ans, dp[n][g].first);
    }
    cout << ans;
}

/*
7 3
1
15
7
9
2
5
10

*/