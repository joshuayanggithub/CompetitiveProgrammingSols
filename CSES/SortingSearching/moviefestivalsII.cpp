#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin >> n >> k;
    vector<pair<int,int>> times(n);
    multiset<int> employees;
    for (int i=0; i<n; ++i) {
        cin >> times[i].second >> times[i].first;
        if (i<k)
            employees.insert(0);
    }
    sort(times.begin(),times.end());
    int ans = 0;
    for (int i=0; i<n; ++i) {
        auto it = employees.upper_bound(times[i].second);
        if (it != employees.begin()) {
            --it;
            employees.erase(it);
            employees.insert(times[i].first);
            ++ans;
        }
    }
    cout << ans;
}