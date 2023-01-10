#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Point {
    int x,y,sumxdist, sumydist;
};
bool sortByX(Point& p1, Point& p2) {
    if (p1.x == p2.x) {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}
bool sortByY(Point& p1, Point& p2) {
    if (p1.y == p2.y) {
        return p1.x < p2.x;
    }
    return p1.y < p2.y;
}

const int mxN = 1e5+1;
int n;
const int mod = 1e9+7;

signed main() {
    freopen("triangles.in","r",stdin);
    freopen("triangles.out","w",stdout);
    cin >> n;
    vector<Point> points;
    for (int i=0; i<n; ++i) {
        int a,b;
        cin >> a >> b;
        Point p = {a,b,0,0};
        points.push_back(p);
    }
    sort(points.begin(),points.end(),sortByY);
    int ptr = 0, cur = 0;
    while (ptr < points.size()) {
        while (points[ptr].y == points[cur].y) {
            ptr++;
        }
        int lastsame = ptr-1;
        vector<int> dis; //x distance since all same y
        int sum = 0;
        int numpoints = lastsame - cur + 1;
        for (int i=cur+1; i<=lastsame; ++i) {
            dis.push_back(points[i].x - points[i-1].x);
        }
        for (int i=0; i<dis.size(); ++i) {
            sum += (dis.size()-i)*dis[i];
        }
        points[cur].sumxdist = sum;
        for (int i=cur+1; i<=lastsame; ++i) {
            int num = i-cur; //number 1;
            sum += (num*2-numpoints)*dis[num-1]; //zero-indexed num
            points[i].sumxdist = sum;
        }
        cur = ptr;
    }
    sort(points.begin(),points.end(),sortByX);
    ptr = 0, cur = 0;
    while (ptr < points.size()) {
        while (points[ptr].x == points[cur].x) {
            ptr++;
        }
        int lastsame = ptr-1;
        vector<int> dis; //y distance since all same x
        int sum = 0;
        int numpoints = lastsame - cur + 1;
        for (int i=cur+1; i<=lastsame; ++i) {
            dis.push_back(points[i].y - points[i-1].y);
        }
        for (int i=0; i<dis.size(); ++i) {
            sum += (dis.size()-i)*dis[i];
        }
        points[cur].sumydist = sum;
        for (int i=cur+1; i<=lastsame; ++i) {
            int num = i-cur; //number 1;
            sum += (num*2-numpoints)*dis[num-1]; //zero-indexed num
            points[i].sumydist = sum;
        }
        cur = ptr;
    }
    int ans = 0;
    for (int i=0; i<points.size(); ++i) {
        if (points[i].sumxdist == 0 && points[i].sumxdist != 0)
            points[i].sumxdist = 1;
        if (points[i].sumydist == 0 && points[i].sumydist != 0)
            points[i].sumydist = 1;
        ans += (((points[i].sumxdist)%mod)*((points[i].sumydist)%mod))%mod;
        ans %= mod;
    }
    cout << ans;

}