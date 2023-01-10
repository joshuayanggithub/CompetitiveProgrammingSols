#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> v(n);
    for (int i=0; i<n; ++i) {cin >> v[i];}
    stack<pair<int,int>> s;
    long long ans = 0;
    for (int i=0; i<n; ++i) {
        while (s.size() >0) {
            if (v[i] > s.top().first) {
                ans += (i-s.top().second+1);
                s.pop();
            }
            else {
                ans += (i-s.top().second+1);
                break;
            }
        }
        s.push({v[i],i});
    }
    cout << ans;
}