#include <bits/stdc++.h>
using namespace std;

int n,t;

void solve() {
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0; i<n; ++i)
        cin >> a[i];
    multiset<int> s;
    for (int i=0; i<n; ++i) {
        cin >> b[i];
        s.insert(b[i]);
    }
    int p1 = 0, p2 = 0;
    vector<int> ming(n);
    vector<int> mingind(n);
    vector<int> maxg(n);
    while (p1<n && p2<n) {
        if (a[p1] <= b[p2]) {
            ming[p1] = b[p2];
            mingind[p1] = p2;
            ++p1;
        }
        else {
            ++p2;
        }
    }
    vector<bool> vis(n);
    int bestp = n-1;
    for (int i=n-1; i>=0; --i) {
        while (vis[bestp] && bestp>=0) {
            --bestp;
        }
        int i1 = i;
        while (i-1>=0 && ming[i] == ming[i-1]) {
            --i; //last equal
        }
        int counter = 0;
        for (int j=i; j<=i1; ++j) {
            maxg[j] = b[bestp];
            while (vis[mingind[j]+counter] == true) {
                ++counter;
            }
            vis[mingind[j]+counter] = true;
        }
    }
    for (int i=0; i<n; ++i)
        cout << ming[i]-a[i] << " ";
    cout << "\n";
    for (int i=0; i<n; ++i)
        cout << maxg[i]-a[i] << " ";
    cout << "\n";
}
int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    cin >> t;
    while (t--) {
        solve();
    }
}