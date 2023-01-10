#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,q;
    cin >> n;
    string s;
    cin >> s;
    cin >> q;
    for (int i=0; i<q; ++i) {
        int m; cin >> m;
        char c; cin >> c;
        int l,r,ind,ans,numc;
        l = r = ind = ans = numc = 0;
        while (r < n && l<=r) {
            if (s[r] == c) {
                ++numc;
            }
            if (r - l + 1 - numc > m) {
                if (s[l] == c) {
                    --numc;
                }
                ++l;
            }
            else {
                ans = max(ans, r-l+1);
                ++r;
            }
        }
        cout << ans << "\n";
    }
}