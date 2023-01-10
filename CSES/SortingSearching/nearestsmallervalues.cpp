#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    set<int> s;
    map<int,int> m;
    for (int i=1; i<=n; ++i) {
        int a; cin >> a;
        auto it = s.lower_bound(a);
        auto it2 = it;
        if (it == s.begin() || s.size() == 0)
            cout << "0 ";
        else {
            --it2;
            cout << m[*it2] <<" ";
        }
        for (;it!=s.end();) {
            m.erase(*it);
            it = s.erase(it);
        }
        s.insert(a);
        m[a]=i;
    }
}