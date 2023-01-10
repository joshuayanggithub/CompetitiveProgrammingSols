#include <bits/stdc++.h>
using namespace std;

long long n, cur;
int a[(int) 2e5+1];
int main() {
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
    }
    sort(a,a+n);
    for (int i=0; i<n; ++i) {
        if (a[i]>cur+1) {
            cout << cur+1;
            return 0;
        }
        else    
            cur += a[i];
    }
    cout << cur+1;
}