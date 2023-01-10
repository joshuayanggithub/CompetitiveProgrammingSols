#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long

signed main() {
    int n; cin >> n;
    vector<pair<int,int>> r1(n/2);
    vector<pair<int,int>> r2(n-n/2);
    int gx, gy; cin >> gx >> gy;
    for (int i=0; i<(n/2); ++i) {
        cin >> r1[i].x >> r1[i].y; 
    }
    for (int i=0; i<(n-n/2); ++i) {
        cin >> r2[i].x >> r2[i].y; 
    }
    unordered_map<int,vector<pair<int,int>>> m1, m2;
    ll xsum, ysum;
    int counter;
    for (int i=0; i<(1<<(n-n/2)); ++i) {
        xsum =0; ysum = 0;
        counter = 0;
        for (int j=0; j<(n-(n/2)); ++j) {
            if (((1<<(j)) & i)) {
                xsum += r2[j].x;
                ysum += r2[j].y;
                ++counter;
            }
        }
        m2[xsum].push_back({ysum,counter});
        if (i>=(1<<n/2))
            continue;
        xsum =0, ysum = 0;
        counter = 0;
        for (int j=0; j<(n/2); ++j) {
            if (((1<<(j)) & i)) {
                xsum += r1[j].x;
                ysum += r1[j].y;
                ++counter;
            }
        }
        m1[xsum].push_back({ysum, counter});
    }
    vector<int> ans(n+1);
    for (auto& val: m1) {
        ll x_ = val.first;
        ll x2_ = gx - x_; //what you want
        if (!m2.count(x2_)) {
            continue;
        }
        for (auto& next: val.second) { //vector of y sums
            ll y_ = next.first;
            ll y2_ = gy - y_;
            int c = next.second;
            for (auto& next2: m2[x2_]) {
                if (y2_ == next2.first) {
                    ans[c+next2.second]++;
                }
            }
        }
    }
    for (int i=1; i<=n; ++i) {
        cout << ans[i] << "\n";
    }
}