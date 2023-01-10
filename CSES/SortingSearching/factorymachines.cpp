#include <bits/stdc++.h>
using namespace std;
#define int long long

long long n,t;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> t;
    vector<int> m(n);
    for (int i=0; i<n; ++i) {
        cin >> m[i];
    }
    long long l=1, r=1e18+1;
    while (l<r){
        long long time = (l+r-1)/2;
        long long made=0;
        for (int i=0; i<n; ++i) {
            int add = time/m[i];
            made += add;
            if (made>=t) break;
        }
        if (made>=t) {
            r=time;
        }
        else
            l = time+1;
    }
    cout << l;

}