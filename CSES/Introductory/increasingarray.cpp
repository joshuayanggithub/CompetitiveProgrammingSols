#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
int main() {
    cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
    }
    ll ans = 0;
    for (int i=1; i<n; ++i) {
        ans += max(0, v[i-1]-v[i]);
        v[i] = max(v[i],v[i-1]);
    }
    cout << ans;
}
