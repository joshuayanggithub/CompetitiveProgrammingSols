#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
const int ma = 1e3+1;
int dp[ma][ma], n;

int main() {
    cin >> n;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            char c; cin >> c;
            if (c == '*') {
                dp[i][j] = -1;
                continue;
            }
            dp[i][j] = (dp[i-1][j] == -1 ? 0 : dp[i-1][j]) + (dp[i][j-1] == -1 ? 0 : dp[i][j-1]); 
            if (i==1 && j==1)
                dp[1][1] = 1;
            dp[i][j] %= mod;
        }
    }
    cout << (dp[n][n] == -1 ? 0 : dp[n][n]);
}
