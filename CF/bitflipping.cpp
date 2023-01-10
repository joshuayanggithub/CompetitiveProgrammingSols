#include <bits/stdc++.h>
using namespace std;

int n,k;
string s;

void solve() {
    cin >> n >> k >> s;
    string ans = s;
    int operations = k;
    vector<int> flips(n);
    for (int i=0; i<s.length(); ++i) {
        int c = s[i] - '0';
        if ((c+k) %2 == 0) { //this means we need to change this number;
            if (operations > 0) {
                operations--;
                flips[i] = 1;
                ans[i] = '1';
            }
            else {
                ans[i] = '0';
            }
        }
        else {
            ans[i] = '1';
        }
    }
    if (operations > 0) { //use them up on the last guy;
        flips[n-1] += operations;
        ans[n-1] = (operations%2 == 1) ? '0' : '1';
    }
    cout << ans << "\n";
    for (int i=0; i<flips.size(); ++i) {
        cout << flips[i] << (i==n-1 ? "\n": " ");
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}