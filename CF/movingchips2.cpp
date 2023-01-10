#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int t,n;
const int MAXN = 2e5+1;
int dp[MAXN][2];
char board[MAXN][2];

//not own-solved :(

void solve() {
    int ans =0;
    cin >> n;
    for (int i=0; i<2; ++i) {
        string s; 
        cin >> s;
        for (int j=0; j<n; ++j) {
            board[j][i] = s[j];
        }
    }
    int first = 0;
    int last = n;
    for (int i=0; i<n; ++i) {
        if (board[i][0] == '*' || board[i][1] == '*') {
            first = i;
            break;
        }
    }
    for (int i=n-1; i>=0; --i) {
        if (board[i][0] == '*' || board[i][1] == '*') {
            last = i;
            break;
        }
    }
    dp[0][0] = (board[0][1] == '*');
    dp[0][1] = (board[0][0] == '*');
    for (int i=1; i<n; ++i) {
        dp[i][0] = INT_MAX; dp[i][1] = INT_MAX;
        dp[i][0] = min(dp[i][0], dp[i-1][0] + 1 + (board[i][1] == '*'));
        dp[i][1] = min(dp[i][1], dp[i-1][1] + 1 + (board[i][0] == '*'));
        dp[i][0] = min(dp[i][0], dp[i-1][1] + 2);
        dp[i][1] = min(dp[i][1], dp[i-1][0] + 2);
    }
    cout << min(dp[n-1][0],dp[n-1][1]) - first - (n-1-last) << "\n";
    //reset
    for (int i=0; i<=n; ++i) {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
}
int main() {
    cin >> t;
    while (t--) {
        solve();
    }
}