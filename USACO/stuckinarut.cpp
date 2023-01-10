#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Collision {
    int t,n,e;
};
struct Cow {
    int x,y;
    char d;
};
bool comp(const Collision& c1, const Collision& c2) {
    return c1.t < c2.t;
};
int n;
Cow c[1000];
vector<Collision> collisions;
bool stopped[1000];
vector<int> blame[1000];
bool vis[1000];
int b;

void dfs(int node) {
    vis[node] = true;
    for (auto next: blame[node]) {
        if (!vis[next]) {
            dfs(next);
            ++b;
        }
    }
}
signed main() {
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> c[i].d >> c[i].x >> c[i].y;
    }
    for (int i=0; i<n; ++i) {
        for (int j=i+1; j<n; ++j) {
            if (c[i].d == c[j].d) {
                continue;
            }
            if (c[i].d == 'N' && c[i].y > c[j].y || c[j].d == 'N' && c[j].y > c[i].y) {
                continue;
            }
            if (c[i].d == 'E' && c[i].x > c[j].x || c[j].d == 'E' && c[j].x > c[i].x) {
                continue;
            }
            int t = max(abs(c[i].x-c[j].x),abs(c[i].y-c[j].y));
            if (c[i].d == 'E') {
                collisions.push_back({t,j,i});
            }
            else {
                collisions.push_back({t,i,j});
            }
        }
    }
    sort(collisions.begin(),collisions.end(),comp);
    for (int i=0; i<collisions.size(); ++i) {
        int c1 = collisions[i].n;
        int c2 = collisions[i].e;
        if (stopped[c1] || stopped[c2]) {
            continue;
        }
        if (abs(c[c1].y -c[c2].y) < abs(c[c1].x - c[c2].x)) {
            stopped[c2] = true; //eastern stops
            blame[c1].push_back(c2);
        }
        else if (abs(c[c1].y -c[c2].y) > abs(c[c1].x - c[c2].x)) {
            stopped[c1] = true;
            blame[c2].push_back(c1);
        }
    }
    for (int i=0; i<n; ++i) {
        b = 0;
        memset(vis,false,sizeof(vis));
        dfs(i);
        cout << b << "\n";
    }
}