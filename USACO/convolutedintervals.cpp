#include <bits/stdc++.h>
using namespace std;

int main () {
    int n,m;
    cin >> n >> m;
    //long long start[2*m+1]; //sums
    vector<long long> s (m+1);
    //long long end[2*m+1];
    vector<long long> e(m+1);
    vector<long long> in(2*m+1);
    for (int i=0; i<n; ++i) {
        int a,b;
        cin >> a >> b;
        s[a]++; 
        e[b]++;
    }
    for (int i=0; i<=m; ++i) {
        if (s[i] == 0) {
            continue;
        }
        for (int j=0; j<=m; ++j) {
            if (s[j] == 0) {
                continue;
            }
            in[i+j] += s[i] * s[j];
        }
    }
    for (int i=0; i<=m; ++i) {
        if (e[i] == 0) {
            continue;
        }
        for (int j=0; j<=m; ++j) {
            if (e[j] == 0) {
                continue;
            }
            if (i+j+1 <= 2*m)
                in[i+j+1] -= e[i] * e[j];
        }
    }
    long long counter = 0;
    for (int i=0; i<=2*m; ++i) {
        counter += in[i];
        cout << counter << "\n";
    }
}