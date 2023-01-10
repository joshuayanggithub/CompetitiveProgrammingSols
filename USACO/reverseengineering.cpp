#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m; cin >> n >> m;
    vector<pair<string,int>> inputs(m);
    for (int i=0; i<m; ++i) {
       cin >> inputs[i].first >> inputs[i].second;
    }
    vector<bool> removed(m);
    while (true) {
        bool noneworks = true;
        for (int i=0; i<n; ++i) {
            for (char in='0'; in<='1'; ++in) {
                int expected=-1;
                bool works = true;
                for (int j=0; j<m; ++j) {
                    if (removed[j]) continue;
                    if (inputs[j].first[i] == in && expected==-1) {
                        expected = inputs[j].second;
                    }
                    if ( (inputs[j].first[i] == in && inputs[j].second != expected)) {
                        works = false;
                        break;
                    }   
                }
                if (works) {
                    for (int ind=0; ind<m; ++ind) {
                        if (removed[ind]) continue;
                        if (inputs[ind].first[i] == in && inputs[ind].second == expected) {
                            removed[ind] = true;
                            noneworks = false;
                        }
                    }
                }
            }
        }
        if (noneworks)
            break;
    }
    for (int i=0; i<m; ++i) {
        if (!removed[i]) {
            cout << "LIE\n";
            return;
        }
    }
    cout << "OK\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}