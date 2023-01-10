#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,x;

signed main() {
    cin >> n >> x;
    vector<pair<int,int>> a(n);
    for (int i=0; i<n; ++i) {
        cin >> a[i].first; a[i].second =i+1;
    }
    sort(a.begin(),a.end());
    int i=0, j=a.size()-1;
    while (i<j) {
        if (a[i].first + a[j].first > x) {
            --j;
        }
        else if (a[i].first + a[j].first == x) {
            cout << a[i].second << " " << a[j].second;
            return 0;
        }
        else {
            i++;
        }
    }
    cout << "IMPOSSIBLE";
}