#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    vector<int> a(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
    }
    vector<pair<int,int>> lacking;
    //lacking.push_back({0,1});
    for (int i=2; i<=n; ++i) {
        if (a[i] < a[i-1]) {
            lacking.push_back({a[i-1]-a[i],i});
        }
    }
    sort(lacking.begin(),lacking.end());
    int p = 0;
    for (int i=1; i<=n; ++i) {
        if (lacking.size() == 0) {
            cout << "1 ";
            continue;
        }
        lacking[p].first -= i;
        cout << lacking[p].second << " ";
        if (p+1<lacking.size() && lacking[p].first <= 0)
            ++p;
    }
    cout << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}