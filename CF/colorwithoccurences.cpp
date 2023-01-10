#include <bits/stdc++.h>
using namespace std;

int n, t;
string s;

void solve() {
    cin >> s;
    cin >> n;
    vector<string> str(n);
    vector<array<int,3>> occurences;
    vector<pair<int,int>> ans;
    for (int i=0; i<n; ++i) {
        cin >> str[i];
        for (int j=0; j<s.length(); ++j) {
            if (s.substr(j,str[i].length()) == str[i]) {
                occurences.push_back({j,j+(int) str[i].length()-1,i});
            }
        }
    }
    sort(occurences.begin(),occurences.end());
    int need = 0;
    int p = 0;
    while (need<s.length() && p<occurences.size()) {
        int bestp = -1;
        int maxr = -1;
        while (p<occurences.size() && occurences[p][0] <= need) {
            if (occurences[p][1] > maxr) {
                bestp = p;
                maxr = occurences[p][1];
            }
            ++p;
        }
        if (bestp==-1) {
            cout << "-1\n"; 
            return;
        }
        else {
            ans.push_back({occurences[bestp][2]+1,occurences[bestp][0]+1});
            need = maxr+1;
        }
    }
    if (need<s.length() || ans.size() == 0) {
        cout << "-1\n"; 
        return;
    }
    cout << ans.size() << "\n";
    for (auto& [a,b]: ans) {
        cout << a << " " << b << " \n";
    }
}

int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    int q; cin >> q;
    while (q--) {
        solve();
    }
}