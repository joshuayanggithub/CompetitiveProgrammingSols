#include <bits/stdc++.h>
using namespace std;

int t,n;
string s;

void solve() {
    cin >> n >> s;
    vector<int> v;
    v.push_back(1);
    for (int i=1; i<n; ++i) {
        if (s[i] == s[i-1]) {
            ++v[v.size()-1] %= 2;
        }
        else {
            v.push_back(1);
        }
    }
    int ans = 0;
    for (int i=0; i<v.size(); ++i) {
        if (v[i] == 1) {
            //if (i <= v.size() -1) {
                ++v[i+1] %= 2;
            //}
            ++ans;
        }
    }
    cout << ans<< "\n";
}
int main() {
    cin >> t;
    while (t--) {
        solve();
    }
}