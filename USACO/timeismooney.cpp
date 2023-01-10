#include <bits/stdc++.h>
using namespace std;

int n,m,c;
long long dp[1000+1][500+1];
int money[1001];
vector<int> adj[1001];

int main() {
    freopen("time.in","r",stdin);
    freopen("time.out","w",stdout);
    cin >> n >> m >> c;
    for (int i=1; i<=n; ++i) { cin >> money[i]; }
    for (int i=0; i<m; ++i) {
        int a,b; cin >> a >> b;
        adj[a].push_back(b);
    }
    // C* ((T+1)^2 -T^2) = C*(2T + 1) <= 500 -> T <= 500
    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=500; ++j) {
            dp[i][j] = -100000;
        }
    }
    dp[1][0] = 0;
    long long ans =0;
    for (int T=1; T<=500; ++T) {
        for (int city=1; city<=n; ++city) {
            for (int next: adj[city]) {
                dp[next][T] = max(dp[city][T-1] + money[next], dp[next][T]);
            }
        }
        ans = max(ans, dp[1][T] - c*T*T);
    }
    cout << ans;
}