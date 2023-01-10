#include <bits/stdc++.h>
using namespace std;

int n,m;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    multiset<int> tickets;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        tickets.insert(a);
    }
    for (int i=0; i<m; ++i) {
        int a; cin >> a;
        auto it = tickets.upper_bound(a);
        if (it == tickets.begin()) {
            cout << "-1\n";
        }
        else {
            --it;
            cout << *it << "\n";
            tickets.erase(it);
        }
    }
}