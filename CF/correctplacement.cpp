#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

struct Edge {
    int x,y,p;
};
bool comp(const Edge&a, const Edge& b) {
    return a.p < b.p;
}
bool operator<(const Edge& a, const Edge& b) {
    if (a.x <= b.x && a.y <= b.y || a.x <= b.y && a.y <= b.x) {
        return true;
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    for (int j=0; j<t; ++j) {
        int n;
        cin >> n;
        Edge friends[n+1];
        friends[0] = {0,0,-1};
        for (int i=1; i<=n; ++i) {
            int a,b;
            cin >> a >> b;
            friends[i] = {a,b,i};
        }
        sort(friends, friends+n+1);
        int sx = friends[1].x;
        int sy = friends[1].y;
        int pos = friends[1].p;
        sort(friends, friends+n+1, comp);
        for (int i=1; i<=n; ++i) {
            if ( (friends[i].x > sx && friends[i].y > sy) || (friends[i].x > sy && friends[i].y > sx)) {
                cout << pos << " ";
            }
            else {
                cout << "-1 ";
            }
        }
        cout << "\n";
    }
}

/*
1
9
4 7
9 2
5 10
10 8
9 2
10 7
9 8
1 10
6 3
*/