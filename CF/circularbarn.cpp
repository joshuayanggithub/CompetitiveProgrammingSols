#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 5e6;
int precomp[maxn+1];

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
    vector<int> moves(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
        //moves[i] = (v[i]+4)/4;
    }
    for (int i=1; i<=maxn; ++i) {
        precomp[i] = (i+4)/4;
    }
    precomp[2] = precomp[1] = precomp[3] = 1;
    for (int i=4; i<=maxn; ++i) {
        if (takeOne(i)) {
            precomp[i] = 1; 
            continue;
        }
        if (v[i]%4 == 0) {
            precomp[i] = min({precomp[i-1],precomp[i-2],precomp[i-3]})+1;
        }
        else {
            precomp[i] = min({precomp[i-1],precomp[i-2],precomp[i-3]})+1;
        }
    }
    int mi = 0;
    for (int i=0; i<n; ++i) {
       if (precomp[v[i]] < precomp[v[mi]]) {
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