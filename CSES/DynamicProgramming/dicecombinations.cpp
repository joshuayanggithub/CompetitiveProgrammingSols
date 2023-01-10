#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 +7;

int main() {
	int n; cin >> n;
	vector<int> dp(n+1);
	for (int i=0; i<n; ++i) {
		for (int j=1; j<=6; ++j) {
			if (i+j <=n) {
				dp[i+j] += dp[i] + (i==0);
				dp[i+j]%=mod;
			}
		}
	}
	cout << dp[n];
}

