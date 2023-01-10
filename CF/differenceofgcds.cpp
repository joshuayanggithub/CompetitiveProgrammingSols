#include <bits/stdc++.h>
using namespace std;

int n,l,r;

bool prime(int num) {
    for (int i=1; i*i<=num; ++i) {
        if (num%i == 0)
            return false;
    }
    return true;
}
void solve() {
    cin >> n >> l >> r;
    bool works = true;
    vector<int> ans;
    for (int i=1; i<=n; ++i) {
        int leastdivofi = ceil((double)l/i)*i; //uh oh double
        if (i>=l && i<=r) {
            leastdivofi = i;
        }
        else if (i > 1) {
            //leastdivofi = leastdivofi + i;
        }
        if (leastdivofi > r) {
            works = false;
            break;
        }
        ans.push_back(leastdivofi);
    }
    if (works)
        cout << "YES\n";
    else {
        cout << "NO\n";
        return;
    }
    for (int i=0; i<ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}