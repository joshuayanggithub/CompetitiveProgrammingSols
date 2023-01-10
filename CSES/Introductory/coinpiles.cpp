#include <bits/stdc++.h>
using namespace std;

int n,t,a,b;

int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        int tr = (a+b)/3;
        if (tr*3 == (a+b) && tr<=a && tr<=b)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    
}