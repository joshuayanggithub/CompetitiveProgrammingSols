#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x; 
    cin >> n >> x;
    map<int,int> m;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        m[a]++;
    }
    bool works = true;
    for (auto it=m.begin(); it!=m.end(); ++it) {
        auto& next = *it;
        if (next.first != x && next.second%(next.first+1) != 0) {
            works=false;
            break;
        }
        if (next.first == x) {
            break;
        }
        m[next.first+1] += next.second/(next.first+1);
    }
    if (works)
        cout << "Yes";
    else
        cout << "No";
}