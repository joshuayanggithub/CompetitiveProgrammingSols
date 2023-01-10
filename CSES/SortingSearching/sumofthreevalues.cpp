#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,x,sum;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> x; 
    vector<pair<ll,ll>> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i].first;
        v[i].second = i+1;
        sum += v[i].first;
    }
    sort(v.begin(),v.end());
    for (int k=0; k<n; ++k) {
        int sum2 = x-v[k].first;
        int l=k+1,r=n-1;
        while (l<r) {
            if (v[l].first + v[r].first > sum2) {
                --r;
            }
            else if (v[l].first + v[r].first == sum2) {
                cout << v[l].second << " " << v[r].second << " " << v[k].second;
                return 0;
            }
            else {
                ++l;
            }
        }
    }
    cout <<"IMPOSSIBLE";
}