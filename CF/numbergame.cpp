#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n; cin >> n;
    int a[n];
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    sort(a,a+n);
    int l=0, r=(n+1)/2;
    while (l<r) {
        int mid = (l+r+1)/2;
        int k = mid;
        int i = n-1;
        int j= 0;
        bool works = true;
        while (i >= j && k > 0) {
            while (i>=j && a[i] > k) {
                --i;
            }
            if (i>=j && a[i] <= k) {
                --k;
                i--; 
                j++; //Bob takes another one automatically
            }
        }
        if (k != 0) {
            works = false;
        }
        if (works) {
            l = mid;
        }
        else {
            r = mid-1;
        }
    }
    cout << l << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}