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
    vector<vector<ll>> m1, m2;
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
        m2.push_back({xsum,ysum,counter});
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
        m1.push_back({xsum,ysum, counter});
    }
    sort(m1.begin(), m1.end());
    sort(m2.begin(), m2.end());
    vector<ll> ans(n+1);
    int p1 = 0, p2 = m2.size()-1;
    ll prevx_ = 1e9+1, prevy_ = 1e9+1;//numbers you know are not possible
    while (p1 < m1.size() && p2 >=0) {
        ll x_ = m1[p1][0];
        ll y_ = m1[p1][1];
        int same = 0;
        vector<ll> appearances1 (n/2+1);
        appearances1[m1[p1][2]]++;
        //vector<ll> counter1 = {m1[p1][2]};
        while (p1+1< m1.size() && x_ == m1[p1+1][0] && y_ == m1[p1+1][1]) {
            ++same;
            //counter1.push_back(m1[p1+1][2]);
            appearances1[m1[p1+1][2]]++;
            ++p1;
        }
        ll xw = gx - x_; //what you want
        ll yw = gy - y_;
        while (p2 >= 0 && m2[p2][0] >= xw) { //&&  m2[p2][1] >= yw
            if (m2[p2][0] == xw && m2[p2][1] == yw) {
                ll same2 = 0;
                //vector<ll> counter2 = {m2[p2][2]};
                vector<ll> appearances2 (n-n/2+1);
                appearances2[m2[p2][2]]++;
                while (p2-1>=0 && xw == m2[p2-1][0] && yw== m2[p2-1][1]) {
                    ++same2;
                    //counter2.push_back(m2[p2-1][2]);
                    appearances2[m2[p2-1][2]]++;
                    --p2;
                }
                for (int i=0; i<appearances1.size(); ++i) {
                    for (int j=0; j<appearances2.size(); ++j) {
                        ans[i+j] += (appearances1[i]*appearances2[j]);
                    }
                }
            }
            if (m2[p2][0] == xw && m2[p2][1] < yw) {
                break;
            }
            --p2;
        }
        ++p1;
    }
    for (int i=1; i<=n; ++i) {
        cout << ans[i] << "\n";
    }
}