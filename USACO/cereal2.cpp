#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;
int type[maxn];
struct Cow {
    int a,b,i;
};
bool comp(const Cow& p1, const Cow& p2) {
    /*if (max(type[p1.first],type[p1.second]) > max(type[p2.first],type[p2.second])) {
        return min(type[p1.first],type[p1.second]) > min(type[p2.first],type[p2.second]);
    }
    return max(type[p1.first],type[p1.second]) > max(type[p2.first],type[p2.second]);*/
    return (type[p1.a] + type[p1.b]) > (type[p2.a]+type[p2.b]);
}
int main() {
    int n,m;
    cin >> n >> m;
    Cow cows[n];
    for (int i=0; i<n; ++i) {
        int a,b;
        cin >> a >> b;
        cows[i] = {a,b,i+1};
        type[a]++;
        type[b]++;
    } 
    sort(cows,cows+n,comp);
    vector<bool> vis(m+1);
    int ans = 0;
    for (int i=0; i<n; ++i) {
        int i1 = cows[i].a;
        int i2 = cows[i].b;
       /* if (type[cows[i].b] < type[cows[i].b]) {
            i2 = cows[i].b;
            i1 = cows[i].a;
        }*/
        if (!vis[i1]) {
            vis[i1] = true;
            ++ans;
        }
        else if (!vis[i2]) {
            vis[i2] = true;
            ++ans;
        }
    }
    cout << n-ans << "\n";
    for (int i=0; i<n; ++i) {
        cout << cows[i].i << "\n";
    }
}