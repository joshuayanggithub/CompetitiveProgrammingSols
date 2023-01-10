#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b) {
    if (b==0) return a;
    return gcd(b, a%b);
}
void solve() {
    int n; cin >> n;
    vector<int> a (n);
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    int g = a[0];
    for (int i=0; i<n; ++i) {
        g = gcd(g,a[i]);
    }
    //g = max (g,1);
    if (a[n-1] ==1 || g==1) {
        cout << "0\n";
        return;
    }
    if (gcd(g,n) == 1) {
        cout << "1\n";
        return;
    }
    if (gcd(g,n-1) == 1) {
        cout << "2\n";
        return;
    }
    cout << "3\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}