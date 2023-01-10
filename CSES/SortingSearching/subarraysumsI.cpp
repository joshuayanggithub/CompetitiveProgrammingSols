#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n,x; cin >> n >> x;
    vector<ll> v(n);
    for (ll i=0; i<n; ++i) {
        cin >> v[i];
    }
    ll l=0,r=0,sum=v[0],counter=0;
    for (;l<n && r<n; ++l){
        while (r+1<n && sum+v[r+1]<=x) {
            ++r; sum += v[r];
        }
        if (sum == x)
            counter++;
        sum -= v[l];
    }
    cout << counter;
}