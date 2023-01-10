#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n,x; cin >> n >> x;
    vector<ll> v(n);
    map<ll,ll> m;
    m[0] = 1;
    ll sum=0, counter=0;
    for (ll i=0; i<n; ++i) {
        cin >> v[i];
        sum += v[i];
        if (m.count(sum-x)) {
            counter += m[sum-x];
        }
        m[sum]++;
    } 
    cout << counter;
}