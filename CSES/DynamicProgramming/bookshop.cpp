#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x; 
	cin >> n >> x;
	vector<pair<int,int> > books(n+1);
	vector<vector<int> > dp(n+1,vector<int>(x+1,0));
	for (int i=1; i<=n; ++i) {
		cin >> books[i].first;
	}
    for (int i=1; i<=n; ++i) {
		cin >> books[i].second;
	}
	for (int order=1; order<=n; ++order) {
		for (int price=0; price <=x; ++price) {
			dp[order][price] = dp[order-1][price];
			if (price-books[order].first >=0){
				dp[order][price] = max(dp[order][price],dp[order-1][price-books[order].first] + books[order].second);
            }
		}
	}


	cout << dp[n][x];
} 
