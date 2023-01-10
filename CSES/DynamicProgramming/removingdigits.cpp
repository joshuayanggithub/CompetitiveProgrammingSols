#include <bits/stdc++.h>
using namespace std;

const int ma = 1e6+1;
int dp[ma], n,x;

int main() {
    int n; cin >> n;
    dp[n] = 0;
    for (int i=0; i<n; ++i) {
        dp[i] = ma;
    }
    for (int i=n; i>=0; --i) {
        int temp = i;
        while (temp>0) {
            int dig = temp%10;
            temp /= 10;
            dp[i-dig] = min(dp[i-dig], dp[i]+1);
        }
    }
    cout << dp[0];
}
