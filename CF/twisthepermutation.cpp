#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    vector<int> a(n+1);
    vector<int> pos(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<int> ans;
    for (int num=n; num>=1; --num) {
        vector<int> temp(a);
        int ind = 1;
        for (int i=1; i<=num; ++i) {
            if (a[i] == num) { 
                ind = i;
                break; 
            }
        }
        for (int i=1; i<=num-ind; ++i) {
            a[i] = temp[i+ind];
        }
        for (int i=num-ind+1; i<=n; ++i) {
            a[i] = temp[i-(num-ind)];
        }
        ans.push_back(ind%num);
    }
    reverse(ans.begin(),ans.end());
    for (auto&next: ans) {
        cout << next << " ";
    }
    cout << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}