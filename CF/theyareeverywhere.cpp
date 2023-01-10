#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    string s; cin >> s;
    int l,r;
    l = r =0;
    unordered_map<char, int> map;
    for (int i=0; i<n; ++i) {
        if (map.count(s[i]) == 0) {
            map[s[i]] = -1; //unseen
        }
    }
    int seen = 0;
    int ans = INT_MAX;
    while (l<n && r<n && l<=r) {
        if (map[s[r]] == -1) {
            ++seen;
        }
        map[s[r]] = r;
        if (seen == map.size()) {
            ans = min(ans, r-l+1);
            if (map[s[l]] == l) {
                map[s[l]] = -1;
                --seen;
            }
            ++l;
        }
        else {
            ++r;
        }
    }
    cout << ans;
}