#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,a,b;

int main() {
    cin >> n >> a >> b;
    vector<ll> psums(n+1);
    for (int i=1; i<=n; ++i) {
        int a; cin >> a;
        psums[i] = psums[i-1] + a;
    }
    ll best = -1e18;
    multiset<ll> m;
    for (int i=a; i<=n; ++i) {
        if (i>b) {
            m.erase(m.find(psums[i-b-1]));
        }
        m.insert(psums[i-a]);
        best = max(best, psums[i]-*m.begin());
    }
    cout <<best;
}