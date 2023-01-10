#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<pair<int,int>>d(n);
    for (int i=0; i<n; ++i){
        cin >> d[i].first >>d[i].second;
    }
    sort(d.begin(),d.end());
    ll ans=0, time=0;
    for (int i=0;i<n; ++i) {
        time += d[i].first;
        ans += d[i].second - time;
    }
    cout << ans;
}