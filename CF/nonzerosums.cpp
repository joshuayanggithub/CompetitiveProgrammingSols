#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    vector<int> a(n+1);
    vector<int> pos;
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        if (a[i] != 0) {
            pos.push_back(i);
        }
    }
    if (pos.size()%2 == 1) {
        cout << "-1\n";
        return;
    }
    vector<pair<int,int>> ans;
    int start = 1;
    for (int i=0; i<pos.size(); i+=2) {
        int zeros = pos[i+1] - pos[i]-1;
        if (start != pos[i]) {
            ans.push_back({start,pos[i]-1});
        }
        if (a[pos[i+1]] != a[pos[i]]) {
            ans.push_back({pos[i],pos[i+1]-1});
            ans.push_back({pos[i+1],pos[i+1]});
        }
        else {
            if (zeros == 0) {
                ans.push_back({pos[i],pos[i+1]});
            }
            else {
                ans.push_back({pos[i],pos[i+1]-2});
                ans.push_back({pos[i+1]-1,pos[i+1]});
            }
        }
        start = pos[i+1]+1;
    }
    if (ans.size() == 0) {
        ans.push_back({1,n});
    }
    else if (ans.size() != 0 && ans.back().second < n) {
        ans.push_back({ans.back().second+1,n});
    }
    cout << ans.size() << "\n";
    for (int i=0; i<ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}