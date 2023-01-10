#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long

using P = pair<long long, long long>;
P operator+(P a, P b) { return {a.first + b.first, a.second + b.second}; }
P operator-(P a, P b) { return {a.first - b.first, a.second - b.second}; }

vector<pair<P, int>> all_subsets(const vector<P> &dirs) {
	vector<pair<P, int>> v{{}};
	for (const P &d : dirs) {
		v.resize(2 * v.size());
		for (int i = 0; i < v.size() / 2; i++) {
			v[i + v.size() / 2] = {v[i].first + d, v[i].second + 1};
		}
	}
	//sort(v.begin(), v.end());
	return v;
}

int main() {
    int n; cin >> n;
    vector<P> r1(n);
    int gx, gy; cin >> gx >> gy;
    for (int i=0; i<(n); ++i) {
        cin >> r1[i].x >> r1[i].y; 
    }
    ll xsum, ysum;
    int counter;
    vector<pair<P, int>> m1 = all_subsets(vector<P>(begin(r1), begin(r1) + n / 2));
	vector<pair<P, int>> m2 = all_subsets(vector<P>(begin(r1) + n / 2, end(r1)));
    sort(m1.begin(), m1.end());
    sort(m2.begin(), m2.end());
    vector<ll> ans(n+1);
    int p1 = 0, p2 = m2.size()-1;
    ll prevx_ = 1e9+1, prevy_ = 1e9+1;//numbers you know are not possible
    vector<ll> appearances2;
    while (p1 < m1.size() && p2 >=0) {
        ll x_ = m1[p1].x.x;
        ll y_ = m1[p1].x.y;
        ll xw = gx - x_; //what you want
        ll yw = gy - y_;
        if ((x_ != prevx_ || y_ != prevy_) ) {
            appearances2 = vector<ll> (n-n/2+1);
            /*for (; p2 >=0 && [p2).first > xw; ++p2);
			for (; p2 >=0 && b.at(p2).first == rest; ++p2) {
				++with_num.at(b.at(ib).second);
			}*/
            while (p2 >= 0 && (m2[p2].x.x > xw || (m2[p2].x.x == xw && m2[p2].x.y > yw) ) ) { //&&  m2[p2][1] >= yw
                --p2;
            }
            if (p2>=0 && m2[p2].x.x == xw && m2[p2].x.y == yw) {
                //vector<ll> counter2 = {m2[p2][2]};
                appearances2[m2[p2].y]++;
                while (p2-1>=0 && xw == m2[p2-1].x.x && yw== m2[p2-1].x.y) {
                    //counter2.push_back(m2[p2-1][2]);
                    appearances2[m2[p2-1].y]++;
                    --p2;
                }
                --p2;
            }
        }
        for (int i=0; i<appearances2.size(); ++i) {
            ans[i + m1[p1].y] += appearances2[i];
        }
        prevx_ = x_;
        prevy_ = y_;
        ++p1;
    }
    for (int i=1; i<=n; ++i) {
        cout << ans[i] << "\n";
    }
}