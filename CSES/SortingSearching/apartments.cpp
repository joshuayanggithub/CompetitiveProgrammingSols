#include <bits/stdc++.h>
using namespace std;

int n,m,k,p1,p2,ans;

int main() {
    cin >> n >> m >> k;
    vector<int> apps(n), poss(m);
    for (int i=0; i<n; ++i) {cin >> apps[i];}
    for (int i=0; i<m; ++i) {cin >> poss[i];}
    sort(apps.begin(),apps.end());
    sort(poss.begin(),poss.end());
    while (p1<n && p2<m) {
        if (abs(apps[p1]-poss[p2])<=k) {
            ++p1; ++p2;
            ++ans;
        }
        else if (poss[p2] > apps[p1]+k) {
            ++p1;
        }
        else {
            ++p2;
        }
    }
    cout << ans;
}