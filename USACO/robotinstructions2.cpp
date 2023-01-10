#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define ll long long

struct P {
    ll x,y;
    int count;
};

int main() {
    int n; cin >> n;
    vector<pair<int,int>> r1(n/2);
    vector<pair<int,int>> r2(n-n/2);
    int gx, gy; cin >> gx >> gy;
    for (int i=0; i<(n/2); ++i) {
        cin >> r1[i].f >> r1[i].s; 
    }
    for (int i=0; i<(n-n/2); ++i) {
        cin >> r2[i].f >> r2[i].s; 
    }
    vector<pair<pair<ll,ll>,ll>> m1, m2;
    ll xsum, ysum;
    int counter;
    for (int i=0; i<(1<<(n-n/2)); ++i) {
        xsum =0; ysum = 0;
        counter = 0;
        for (int j=0; j<(n-(n/2)); ++j) {
            if (((1<<(j)) & i)) {
                xsum += r2[j].f;
                ysum += r2[j].s;
                ++counter;
            }
        }
        m2.push_back({{xsum,ysum},counter});
        if (i>=(1<<n/2))
            continue;
        xsum =0, ysum = 0;
        counter = 0;
        for (int j=0; j<(n/2); ++j) {
            if (((1<<(j)) & i)) {
                xsum += r1[j].f;
                ysum += r1[j].s;
                ++counter;
            }
        }
        m1.push_back({{xsum,ysum},counter});
    }
    vector<int> ans(n+1);
    for (auto& val: m1) {
        ll x_ = val.first.f;
        ll y_ = val.first.s;
        ll x2_ = gx - x_; //what you want
        ll y2_ = gy - y_;
        if (!m2.count({x2_,y2_})) {
            continue;
        }
        for (auto& next: val.second) { //vector of y sums
            for (auto& next2: m2[{x2_,y2_}]) {
                ans[next + next2]++;
            }
        }
    }
    for (int i=1; i<=n; ++i) {
        cout << ans[i] << "\n";
    }
}