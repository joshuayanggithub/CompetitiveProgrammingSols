#include <bits/stdc++.h>
using namespace std;

map<int,int> pos;
int cur,ans,start=1;

int main() {
    int n; cin >> n;
    for (int i=1;i<=n; ++i) {
        int a; cin >> a;
        if (pos[a] >= start) {
            cur = i-pos[a];
            start = pos[a]+1;
        }
        else
            ++cur;
        pos[a] = i;
        ans = max(ans,cur);
    }
    cout << ans;
}