#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    int n;
    cin >> n;
    pair<int,int> o[n];
    for (int i=0; i<n; ++i) {
        cin >> o[i].first;
        o[i].second = i;
    }
    sort(o,o+n);
    int ans =0;
    for (int i=0; i<n; ++i) {
        if (o[i].second >= i) {
            ans = max(ans,o[i].second-i);
        }
    }
    cout << ans+1;
}