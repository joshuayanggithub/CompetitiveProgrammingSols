#include <bits/stdc++.h>
using namespace std;

int t,n;
string s;

void solve() {
    cin >> n >> s;
    int ans =0, ans2 = 0;
    char prev = '-';
    for (int i=0; i<n; i=i+2) { //always even
        if (s[i] == s[i+1]) {
            if (s[i] != prev) {
                ++ans2;
            }
            prev = s[i];
        }
        else {
            ++ans;
        }
    }
    if (ans2 == 0) {ans2 = 1;}//special
    cout << ans << " " << ans2 << "\n";
}
int main() {
    cin >> t;
    while (t--) {
        solve();
    }
}