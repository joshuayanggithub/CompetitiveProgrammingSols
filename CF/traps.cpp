#include <bits/stdc++.h>
using namespace std;
#define int long long

//hinted at

int n,t,k;
bool comp(const pair<int,int>& a, const pair<int,int>& b) {
    return  a.first -(n - a.second - 1) > b.first -(n - b.second - 1);
}
void solve() {
    cin >> n >> k;
    pair<int,int> a[n];
    for (int i=0; i<n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a,a+n,comp);
    int damage =0;
    for (int i=0; i<k; ++i) {
        damage += (n - a[i].second - 1);
    }
    damage -= (k)*(k-1)/2;
    for (int i=k; i<n; ++i) {
        damage += a[i].first;
    }
    cout << damage << "\n";
}
signed main() {
    cin >> t;
    while (t--) {
        solve();
    }
}

/*
5
4 4
8 7 1 4
4 1
5 10 11 5
7 5
8 2 5 15 11 2 8
6 3
1 2 3 4 5 6
1 1
7
*/