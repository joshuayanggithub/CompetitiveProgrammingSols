#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    pair<int,int> h[n+1];
    for (int i=1; i<=n; ++i) {
        cin >> h[i].first;
        h[i].second = i;
    }
    stack<pair<int,int>> s;
    long long ans = 0;
    vector<int> decreasing (n);
    int start = 0;
    for (int i=1; i<=n; ++i) {
        while (!s.empty() && s.top().first <= h[i].first) {
            s.pop();
        }
        if (!s.empty()) {
            ans += (long long) i - s.top().second+1;
            //cout << i << " " << s.top().second << "\n";
        }   
        s.push(h[i]);
    }
    while (!s.empty()) {
        s.pop();
    }
    for (int i=n; i>=1; --i) {
        while (!s.empty() && s.top().first <= h[i].first) {
            s.pop();
        }
        if (!s.empty()) {
            ans += (long long) s.top().second - i + 1;
            //cout << i << " " << s.top().second << "\n";
        }   
        s.push(h[i]);
    }
    cout << ans;
}