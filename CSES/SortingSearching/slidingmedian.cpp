#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k; cin >> n >> k;
    vector<int> v(n);
    set<int> s;
    vector<int> temp;
    for (int i=0; i<n; ++i) {
        cin >>v[i];
        if (i<k) {
            s.insert(v[i]);
            temp.push_back(v[i]);
        }
    }
    sort(temp.begin(),temp.end());
    int median = temp[(k-1)/2];
    for (int i=k; i<n; ++i) {
        int offset = 0;
        if (v[i] > median)
            offset//
    }
}