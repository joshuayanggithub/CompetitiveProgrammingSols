#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    set<int> s;
    for (int i=1; i<=n; ++i) {
       s.insert(i);
    }
    auto it = s.begin();
    while (s.size() != 0 ) {
        it++;
        if (it==s.end())
            it = s.begin();
        cout << *it << " ";
        it = s.erase(it);
        if (it==s.end())
            it = s.begin();
    }
}