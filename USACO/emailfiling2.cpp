#include <bits/stdc++.h>
using namespace std;

int n,m,k;

void solve() {
    cin >> m >> n >> k;
    vector<int> emails(n+1);
    vector<pair<int,int>> range_folders(n+1,{INT_MAX,0});
    vector<int> pastfolder(n+1); //all emails <= v[] are filed for this folder i
    for (int i=1; i<=n; ++i) {
        cin >> emails[i];
        range_folders[i].first = min(range_folders[i].first, i);
        range_folders[i].second = max(range_folders[i].second, i);
    }
    for (int l=1; l<=m; ++l) { //left range of folder view, right = l+k-1;
        int r = l+k-1;
        int needreach = range_folders[l].second; //we need to reach this index
        int needl = needreach - (k-1);
        if (needreach <= pastfolder[l])
        for (int i=l; i<=r; ++i) {
            pastfolder[i] = needreach;
        }
    }
}
int main() {
    #ifdef LOCAL
        freopen("zz.in","r",stdin);
    #endif

    int t; cin >> t;
    while (t--) {
        solve();
    }
}