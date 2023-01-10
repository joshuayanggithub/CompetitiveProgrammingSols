#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<array<int,3>> v(n);
    vector<array<int,2>> contains(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i][0] >> v[i][1];
        v[i][2] = i;
    }
    sort (v.begin(), v.end(), [](array<int,3> p1, array<int,3> p2) {
        if (p1[0] == p2[0])
            return p1[1] > p2[1];
        return p1[0] < p2[0];
    });
    int sofar = 0;
    for (int i=0; i<n; ++i) {
        if (v[i][1] <= sofar) {
            contains[v[i][2]][1] = 1;
        }
        sofar = max(sofar,v[i][1]);
    }
    sort (v.begin(), v.end(), [](array<int,3> p1, array<int,3> p2) {
        if (p1[1] == p2[1])
            return p1[0] > p2[0];
        return p1[1] < p2[1];
    });
    sofar = 0;
    for (int i=0; i<n; ++i) {
        if (v[i][0] <= sofar) {
            contains[v[i][2]][0] = 1;
        }
        sofar = max(sofar,v[i][0]);
    }
    for (int i=0; i<n; ++i)
        cout << contains[i][0] << " ";
    cout << "\n";
    for (int i=0; i<n; ++i)
        cout << contains[i][1] << " ";
}