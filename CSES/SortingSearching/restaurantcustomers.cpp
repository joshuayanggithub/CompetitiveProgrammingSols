#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    vector<pair<int,int>> times(2*n);
    for (int i=0; i<2*n; i+=2) {
        cin >> times[i].first >> times[i+1].first;
        times[i].second = 1;
        times[i+1].second = -1;
    }
    sort(times.begin(),times.end());
    int ma=0,cur=0;
    for (int i=0; i<2*n; ++i) {
        cur += times[i].second;
        ma = max(ma,cur);
    }
    cout << ma;
}