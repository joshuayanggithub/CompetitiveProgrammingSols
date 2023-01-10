#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    map<int,int> m;   
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        m[a[i]]++;
    }
    int ans =0;
    while (a.size() != 0) {
        set<int> dups;
        for (auto& [k,v]: m) {
            if (v > 1) {
                dups.insert(k);
            }
        }
        for (int i=0; i<a.size(); ++i) {
            int p1 = (i-1+a.size())%a.size();
            int p2 = (i+1+a.size())%a.size();
            if ((a[p1] != a[p2] && dups.count(a[i])) || i == a.size() - 1){
                m[a[i]]--;
                ans++;
                a.erase(a.begin()+i);
                break;
            }
        }
        bool eraseble = true;
        while (eraseble && a.size() != 1) {
            eraseble = false;
            for (int i=0; i<a.size(); ++i) {
                int p1 = (i-1+a.size())%a.size();
                if (a[p1] == a[i]){
                    m[a[i]]--;
                    a.erase(a.begin()+i);
                    eraseble = true;
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}