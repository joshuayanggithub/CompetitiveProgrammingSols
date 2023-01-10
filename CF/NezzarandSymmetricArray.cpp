#include <bits/stdc++.h>
using namespace std;

//editorial solved

int main() {
    int t;
    cin >> t;
    for (int j=0; j<t; ++j) {
        int n;
        cin >> n;
        vector<int> a (2*n);
        for (int i=0; i<2*n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        bool work = true;
        for (int i=0; i<2*n; i+=2) {
            if (a[i] != a[i+1] || a[i] % (i+2) != 0) {
                work = false;
                break;
            }
        }
        if (work) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << "\n";
    }
}