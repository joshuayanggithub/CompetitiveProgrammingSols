#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int>v(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
    }
    multiset<int> s;
    for (int i=0; i<n; ++i) {
        auto it = s.upper_bound(v[i]);
        if (it!=s.end()) {
            s.erase(it);
            s.insert(v[i]);
        }
        else
            s.insert(v[i]);
    }
    cout << s.size();

}