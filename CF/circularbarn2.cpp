#include <bits/stdc++.h>
using namespace std;

int n;

bool takeOne(int x) { //prime
    if (x<=2)
        return true;
    for (int div = 2; div*div <= n; div++) {
        if (n%div == 0)
            return false;
    }
    return true;
}
void solve() {
    cin >> n;
    vector<int> v(n);
    vector<int> v2(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
        v2[i] = (v[i]+4)/4;
        if (takeOne(v[i])) {
            v2[i] = 1;
        }
    }
    int mi = 0;
    int miv = v2[0];
    for (int i=0; i<n; ++i) {
       if (v2[i] < v2[mi]) {
            mi = i;
       }
    }
    if (v[mi]%4 ==0) {
        cout << "Farmer Nhoj\n";
    }
    else {
        cout << "Farmer John\n";
    }
}

int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    int t; cin >> t;
    while (t--) {
        solve();
    }
}