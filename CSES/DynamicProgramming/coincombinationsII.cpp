#include <bits/stdc++.h>
using namespace std;

const int ma = 1e6+1;
const int mod = 1e9+7;
int dp[ma], n,x;

int main() {
	cin >> n >> x;
	vector<int> coins(n+1);
	for (int i=1; i<=n; ++i) { cin >> coins[i];}
    sort(coins.begin(),coins.end());
    dp[0]= 1;
    for (int j=1; j<=n; ++j) {
	    for (int i=0; i<=x; ++i) {
			if (i - coins[j] >= 0) {
                dp[i] += dp[i-coins[j]]; dp[i] %= mod;
            }
        }
    }
    cout << dp[x];
}
