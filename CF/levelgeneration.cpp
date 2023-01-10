#include <bits/stdc++.h>
using namespace std;

int main() {
    long long q;
    cin >> q;
    for (int i=0; i<q; ++i) {
        long long n;
        cin >> n;
        long long r = n;
        long long l = 0;
        long long ans  = 0;
        while (l<r) {
            long long mid = (l+r-1)/2; //one edge
            long long maxconnections = (n-mid)*(n-mid-1)/2 ;
            if ( maxconnections <= mid) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
            ans = max(ans, mid + min(mid,maxconnections));
        }
        ans = max((n-l)*(n-l-1)/2 + l, ans);
        cout << ans << "\n";
    }
}