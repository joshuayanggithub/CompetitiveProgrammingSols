#include <bits/stdc++.h>
using namespace std;


int n,k;
int dp[2][22][3]; //optimized dp

/*
H - 0
P - 1
S - 2
*/
int win(char c1, char c2) {
    if ( (c1 == 'H' && c2 == 'S')  || (c1 == 'S' && c2 == 'P') || (c1 == 'P' && c2 == 'H')) {
        return 1;
    }
    return 0;
}
int main() {
    freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
    cin >> n >> k;
    char c[n];
    char options[] = {'H','P','S'};
    for (int i=0; i<n; ++i) {
        cin >> c[i];
    }
    for (int i=0; i<n; ++i) {
        for (int s=0; s<=k; ++s) { //number of times switched
            for (int j=0; j<3; ++j) {
                dp[(i+1)%2][s][j] = max(dp[(i+1)%2][s][j], dp[i%2][s][j] + win(options[j],c[i]));
                dp[(i+1)%2][s+1][j] = max(dp[(i+1)%2][s+1][j], dp[i%2][s][(j+1)%3] + win(options[j],c[i]));
                dp[(i+1)%2][s+1][j] = max(dp[(i+1)%2][s+1][j], dp[i%2][s][(j+2)%3] + win(options[j],c[i]));
            }
        }
    }
    int ans = 0;
    for (int s=0; s<=k; ++s) {
        ans = max({dp[n%2][s][0], dp[n%2][s][1], dp[n%2][s][2], ans});
    }
    cout << ans;
}

/*
5 1
P
P
H
P
S
*/