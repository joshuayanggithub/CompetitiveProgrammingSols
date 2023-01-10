#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main () {
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	int n,m; cin >> n >> m;
	vector< vector<int> > dp(n+1, vector<int>(m+1));
	vector<int> diff = {-1,0,1};
	for (int i=1; i<=n; ++i) {
		int a;	
		cin >> a;
		if (a == 0) {
			for (int num=1; num<=m; ++num) {
				if (i==1) {
					dp[i][num] = 1;
				}
				for (int d: diff) {
					if (num+d >=1 && num+d <=m) {
						dp[i][d+num] = (dp[i][d+num] + dp[i-1][num]) %mod;
					}
				}
			}
			
		}
		else {
			if (i==1) {
				dp[i][a] = 1;
				continue;
			}
			for (int d: diff) {
				if (d+a >=1 && d+a <=m) {
					dp[i][a] = (dp[i][a] + dp[i-1][a+d]) %mod;
				}
			}	
		}
	}
	int sum=0;
	for (int i=1; i<=m; ++i) {
		sum += dp[n][i];
		sum %= mod;
	}
	cout << sum;
}
