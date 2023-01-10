#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    if (n%4==0) {
        cout << "YES\n";
        cout << n/2 << "\n";
        for (int i=1; i<=n/2; ++i) {
            if (i==n/4+1) {
                cout << "\n" << n/2 << "\n";
            }
            cout << i << " " << n+1-i << " ";
        }
        
    }
    else if ((n+1)%4 == 0) {
        cout << "YES\n";
        cout << n/2 << "\n" << n << " ";
        for (int i=1; i<=(n-1)/2; ++i) {
            if (i==(n+1)/4) {
                cout << "\n" << n/2+1 << "\n";
            }
            cout << i << " " << n-i << " ";
        }
    }
    else {
        cout << "NO SOLUTION";
    }
}