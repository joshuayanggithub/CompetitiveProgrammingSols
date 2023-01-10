#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    set<pair<int,int>> s;
    set<int> rooms;
    for (int i=0; i<n; ++i) { 
        rooms.insert(i+1);
    }
    vector<int> ans;
    int ma = 0;
    for (int i=0; i<n; ++i) {
        int a,b; cin >> a >> b;
        for (auto i=s.begin(); i!=s.end();) {
            if ((*i).first <a) {
                rooms.insert((*i).second);
                i= s.erase(i);
            }
            else
                break;
        }
        int r = *rooms.begin();
        ans.push_back(r);
        ma = max(ma, r);
        rooms.erase(rooms.begin());
        s.insert({b,r});
    }
    cout << ma << "\n";
    for (int a: ans) {
        cout << a << " ";
    }
}