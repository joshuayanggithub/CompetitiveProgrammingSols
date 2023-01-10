#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n,k; cin >> n >> k;
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
    }
    ll l=0, r=2e14+1;
    while (l<r) {
        ll mid = (l+r)/2;
        ll sum=0, groups = 1,i=0;
        while (i<n){
            if (groups>k)
                break;
            if (sum+v[i]<=mid) {
                sum += v[i];
                ++i;
            }
            else {
                ++groups; 
                sum=0;
            }
        }
        if (groups > k)
            l = mid+1;
        else if (groups <= k)
            r=mid;
    }
    cout << l;
}