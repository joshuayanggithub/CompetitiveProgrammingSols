#include <bits/stdc++.h>
using namespace std;

const int ma = 1e6+1;
int dp[ma], n,x;

int main() {
	cin >> n >> x;
	vector<int> coins(n);
	for (int i=0; i<n; ++i) { cin >> coins[i];}
    for (int i=1; i<=x; ++i) {
        dp[i] = ma;
    }
	for (int i=0; i<n; ++i) {
		for (int j=0; j<=x; ++j) {
			if (j+coins[i] <= x)
				dp[j+coins[i]] = min(dp[j+coins[i]], dp[j] + 1);
        }
    }
    cout << (dp[x] == ma ? -1 : dp[x]);
}
