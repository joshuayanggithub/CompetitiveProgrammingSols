#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n;

ll makemod(ll a) {
    return (a%n+n)%n;
}
int main() {
    cin >> n;
    vector<ll> v(n);
    map<ll,ll> m;
    m[0] = 1;
    ll sum=0, counter=0;
    for (ll i=0; i<n; ++i) {
        cin >> v[i];
        sum += v[i];
        sum = makemod(sum);
        if (m.count(makemod(sum-n))) {
            counter += m[makemod(sum-n)];
        }
        m[sum]++;
    } 
    cout << counter;
}