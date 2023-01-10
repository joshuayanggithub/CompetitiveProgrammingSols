#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,k; cin >> n >> k;
    int steps = min(k-1,n-k) + n-1;
    int coins = n;
    int stones = n+1;
    cout << steps+coins+stones << "\n";
}
int main() {
    solve();
}