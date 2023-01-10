#include <bits/stdc++.h>
using namespace std;

int main() {
    #define int long long
    int n;
    cin >> n;
    pair<int,int> lines[2*n];
    vector<int> ans (n+1);
    for (int i=0; i<n; ++i) {
       cin >> lines[2*i].first >> lines[2*i+1].first;
       ++lines[2*i+1].first;
       lines[2*i].second = 1;
       lines[2*i+1].second = -1;
    }
    sort(lines,lines+2*n);
    int counter = 0;
    for (int i=0; i<2*n-1; ++i) {
        counter += lines[i].second;
        if (lines[i+1].first != lines[i].first) { //diff
            ans[counter] += lines[i+1].first - lines[i].first;
        }
    }
    for (int i=1; i<=n; ++i) {
        cout << ans[i] << " ";
    }
}