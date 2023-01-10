#include <bits/stdc++.h>
using namespace std;

long long sum;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int med = n%2 == 0 ? (v[n/2] + v[n/2-1])/2 : v[n/2];
    for (int i=0; i<n; ++i) {
        sum += abs(v[i]-med);
    }
    cout << sum;
}