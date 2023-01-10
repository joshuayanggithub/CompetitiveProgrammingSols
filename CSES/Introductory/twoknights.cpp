#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long

signed main() {
    int n; cin >> n;
    vector<ll> prev(n+1);
    for (int i=1; i<=n; ++i) {
        prev[i]= prev[i-1]+(i-1)*(i-1)*(2*i-1);
        prev[i] += (2*i-1)*(2*i-2)/2;
        if (i>=3) {
            for (int j=1; j<=i; ++j) {
                if (j+1 <=i && 1+2 <=i)
                    prev[i]-=2; 
                if (j-1 >=1 && 1+2 <=i)
                    prev[i]-=2; 
                if (j+2 <=i && 1+1 <=i)
                    prev[i]-=2; 
                if (j-2 >=1 && 1+1 <=i)
                    prev[i]-=2; 
            }
            prev[i]+=4;
        }
        cout << prev[i] << "\n";
    }
}