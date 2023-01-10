#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    vector<pair<int,int>> movies(n);
    for (int i=0; i<n; ++i) {
        cin >> movies[i].second >> movies[i].first;
    }
    sort(movies.begin(),movies.end());
    int ans =0;
    for (int i=0; i<movies.size(); ++ans) {
        int j= i+1;
        while (j<movies.size() && movies[i].first > movies[j].second) {
            ++j;
        }
        i=j;
    }
    cout << ans;
}