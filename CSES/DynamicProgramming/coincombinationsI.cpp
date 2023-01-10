#include <bits/stdc++.h>
using namespace std;

const int ma = 1e6+1;
const int mod = 1e9+7;
int dp[ma], n,x;

int main() {
	cin >> n >> x;
	vector<int> coins(n);
	for (int i=0; i<n; ++i) { cin >> coins[i];}
    dp[0]= 1;
	for (int i=0; i<=x; ++i) {
		for (int j=0; j<n; ++j) {
			if (i+coins[j] <= x)
				dp[i+coins[j]] = (dp[i+coins[j]] + dp[i])%mod;
        }
    }
    cout << dp[x];
}
