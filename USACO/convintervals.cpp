#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

signed main() {
    int n,m;
    cin >> n >> m;
    vector<ll> nline(2*m+2); //max 0-2m 10000
    vector<int> starts(m+2);
    vector<int> ends(m+2);
    for (int i=0; i<n; ++i) {
        int a,b; cin >> a >> b;
        starts[a]++;
        ends[b]++;
    }
    for (int i=0; i<=m; ++i) {
        for (int j=0; j<=m; ++j) {
            nline[i+j] += starts[i]*starts[j];
            nline[i+j+1] -= ends[i]*ends[j];
        }
    }
    ll sofar = 0;
    for (int i=0; i<=2*m; ++i) {
        sofar += nline[i];
        cout << sofar << "\n";
    }
}