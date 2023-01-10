#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    int x=1,y=1;
    for (int i=0; i<6; ++i) {
        int a; cin >> a;
        if (i%2 == 0) {
            x += a;
        }
        else {
            y += a;
        }
    }
    int tx,ty; cin >> tx >> ty;
    x/=3; y/=3;
    if ((x==1 || x ==n) && (y==1 || y==n)) {
        if ((tx==x) || (ty==y)) {
            cout << "YES\n";
        }
        else
            cout << "NO\n";
    }
    else {
        if (abs(x-tx)%2 == 1 && abs(y-ty)%2 == 1) {
            cout << "NO\n";
        }
        else 
            cout << "YES\n";
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