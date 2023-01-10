#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    int cities[n];
    for (int i=0; i<n; ++i) {
        cin >> cities[i];
    }
    int towers[m];
    for (int i=0; i<m; ++i) {
        cin >> towers[i];
    }
    int l,r;
    l = r =0;
    int ans = 0;
    while (l<n) {
        int mindist = INT_MAX;
        while (r<m) {
            if (abs(cities[l] - towers[r]) > mindist) {
                break;
            } 
            else {
                mindist = abs(cities[l] - towers[r]);
                ++r;
            }
        }
        r = max(r-1,0);
        ans = max(ans,mindist);
        ++l;
    }
    cout << ans;
}