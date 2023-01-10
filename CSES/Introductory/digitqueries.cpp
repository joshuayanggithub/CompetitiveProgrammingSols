#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll q,k;

int main() {
    cin >> q;
    while (q--) {
        cin >> k;
        ll dig=1;
        while ((k-(ll)pow(10,dig-1)*9*dig)>=0) {
            k -= (ll)pow(10,dig-1)*9*dig;
            ++dig;
        }
        ll num =(ll)pow(10,dig-1)-1+(k+dig-1)/dig;
        string s = to_string(num);
        cout << s[(k%dig-1+s.length())%s.length()] << "\n";
    }
}