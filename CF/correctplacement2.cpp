#include <bits/stdc++.h>
#define y first
#define p second
using namespace std;

struct Edge {
    int x,y,p,miny,minyi;
};
bool comp(const Edge&a, const Edge& b) {
    return a.p < b.p;
}
bool operator<(const Edge& a, const Edge& b) {
    if (a.x < b.x) {
        return true;
    }
    if (a.x ==b.x && a.y < b.y) {
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
        friends[0] = {0,INT_MAX,0,INT_MAX};
        for (int i=1; i<=n; ++i) {
            int a,b;
            cin >> a >> b;
            friends[i] = {min(a,b),max(a,b),i,INT_MAX};
        }
        sort(friends, friends+n+1);
        for (int i=1; i<=n; ++i) {
            if (friends[i-1].miny < friends[i-1].y) {
                friends[i].miny = friends[i-1].miny;
                friends[i].minyi = friends[i-1].minyi;
            }
            else {
                friends[i].miny = friends[i-1].y;
                friends[i].minyi = friends[i-1].p;
            }
        }
        int recy = 0;
        int recyi = 0;
        for (int i=1; i<=n; ++i) {
            if (friends[i].x == friends[i-1].x) {
                friends[i].miny = recy;
                friends[i].minyi = recyi;
            }
            else {
                recy = friends[i].miny;
                recyi = friends[i].minyi;
            }
        }
        sort(friends,friends+n+1,comp);
        for (int i=1; i<=n; ++i) {
           if (friends[i].y > friends[i].miny) {
               cout << friends[i].minyi << " ";
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