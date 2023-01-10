#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int n;

bool cmp(const pair<int,int>& p1, const pair<int,int>& p2) {
    return p1.f < p2.f;
}

void solve() {
    cin >> n;
    multiset<pair<int,int>,decltype(&cmp)> ppl(cmp);
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        if (a>0)
            ppl.insert({a,i+1});
    }
    vector<pair<int,int>> ans;
    while (ppl.size() > 1) {
        auto p1 = *ppl.rbegin();
        auto p11 = ppl.find(p1);
        auto p111 = *p11;
        ppl.erase(p11);
        auto p2 = *ppl.rbegin();
        auto p22 = ppl.find(p2);
        auto p222 = *p22;
        ppl.erase(p22);
        if (p111.f > 1) {
            ppl.insert({p111.f-1,p111.s});
        }
        if (p222.f > 1) {
            ppl.insert({p222.f-1,p222.s});
        }
        ans.push_back({p111.s,p222.s});
    }
    cout << ans.size() << "\n";
    for (auto& next: ans) {
        cout << min(next.f,next.s) << " " << max(next.f,next.s) << "\n";
    }
    
}

int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    int t; cin >> t;
    while (t--) {
        solve();
    }
}