#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    string s; cin >> s;
    vector<int> m(n);
    for (int i=0; i<n; ++i) {
        cin >> m[i];
    }
    int p = 0;
    vector<pair<int,int>> intervals;
    while (p<n) {
        while (p<n && s[p] == '0') {
            ++p;
        }
        if (p>=n)
            break;
        int start = p;
        while (p<n && s[p] == '1') {
            ++p;
        }
        intervals.push_back({max(0,start-1),p-1});  
    }
    int ans =0;
    for (int i=0; i<intervals.size(); ++i) {
        int sum = 0;
        int smallest = m[intervals[i].first];
        for (int j=intervals[i].first; j<=intervals[i].second; ++j) {
            sum += m[j];
            smallest = min(m[j], smallest);
        }
        if (s[intervals[i].first] == '0')
            sum -= smallest;
        ans += sum;
        //cout << "left" << intervals[i].first << "\n";
    }
    cout << ans << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}