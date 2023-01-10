#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n;

int main() {
    cin >> n;
    ll sum = 0;
    for (int i=0; i<n-1; ++i) { int a; cin >> a; sum += a;}
    cout << n*(n+1)/2 - sum;
}