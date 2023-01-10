#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    set<pair<int,int>> s;
    set<int> rooms;
    vector<array<int,3>> c(n);
    for (int i=0; i<n; ++i) { 
        rooms.insert(i+1);
    }
    for (int i=0; i<n; ++i) {
        cin >> c[i][0] >> c[i][1];
        c[i][2] = i;
    }
    sort(c.begin(),c.end());
    vector<pair<int,int>> ans;
    int ma = 0;
    for (int i=0; i<n; ++i) {
        int a=c[i][0],b=c[i][1];
        for (auto i=s.begin(); i!=s.end();) {
            if ((*i).first <a) {
                rooms.insert((*i).second);
                i= s.erase(i);
            }
            else
                break;
        }
        int r = *rooms.begin();
        ans.push_back({c[i][2],r});
        ma = max(ma, r);
        rooms.erase(rooms.begin());
        s.insert({b,r});
    }
    sort(ans.begin(),ans.end());
    cout << ma << "\n"; 
    for (auto a: ans) {
        cout << a.second << " ";
    }
}