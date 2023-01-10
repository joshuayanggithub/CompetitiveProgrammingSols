#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   
    //freopen("e.in","r",stdin);
    int x,n; cin >> x >> n;
    multiset<int> lengths;
    set<int> lights;
    lights.insert(0);
    lights.insert(x);
    lengths.insert(x);
    for (int i=0; i<n; ++i) {
        int t; cin >> t;
        auto it = lights.lower_bound(t);
        auto it2 = it--;
        lengths.erase(lengths.find(*it2-*it));
        lengths.insert(t-*it);
        lengths.insert(*it2-t);
        lights.insert(t);
        cout << *lengths.rbegin() << " ";
    }

}