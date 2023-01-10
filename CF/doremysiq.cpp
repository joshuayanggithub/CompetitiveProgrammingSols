#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,q;
    cin >> n >> q;
    vector<int> v(n);
    map<int, vector<int>> num;
    for (int i=0; i<n; ++i) {
        cin >> v[i];
        num[v[i]].push_back(i);
    }
    string ans = "";
    for (int i=0; i<n; ++i) {
        if (q <=0) {
            ans += "0";
            continue;
        }
        if (v[i] > q) {
            int test = v[i];
            auto it = lower_bound(num[q].begin(),num[q].end(),i);
            int left = n-1-i+1; //num left including this index
            if (it == num[q].end()) {
                ans += "1";
                --q;
            }
            else {
                int numoftest = num[q].end() - it;
                if (q >= left) {
                    ans += "1";
                    --q;
                }   
                else {  
                    ans += "0";
                }
            }
        }
        else {
            ans += "1";
        }
    }
    cout << ans << "\n";
}
int main () {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}