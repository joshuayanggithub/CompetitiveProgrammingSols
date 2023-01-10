#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    vector<int> stones(n);
    int ma = -1;
    for (int i=0; i<n; ++i) {
        cin >> stones[i];
        ma = max(ma,stones[i]);
    }
    int l = 1; int r = ma;
    while (l<r) {
        int mid = (l+r+1)/2;
        bool works = true;
        vector<int> temp(stones);
        for (int i=n-1; i>=2; --i) {
            int give = max(0,min(temp[i]-mid,stones[i]));
            temp[i] -= give/3*3;
            temp[i-2] += give/3*2;
            temp[i-1] += give/3;
            if (temp[i]<mid) {
                works = false;
                break;
            }
        }
        if (temp[1]<mid || temp[0]<mid)
            works = false;
        if (works)
            l=mid;
        else
            r=mid-1;
    }
    cout << l << "\n";
}

int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    int t; cin >> t;
    while (t--) {
        solve();
    }
}