#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second

int n;
const int mxN = 2501;
int psums[mxN][mxN];

bool sortY(pair<int,int> p1, pair<int,int> p2) {
    if (p1.y == p2.y) {
        return p1.x < p2.x;
    }
    return p1.y < p2.y;
}

signed main() {
    cin >> n;
    vector<pair<int,int>> points;
    for (int i=0; i<n; ++i) {
        int a,b;
        cin >> a >> b;
        points.push_back({a,b});
    }
    sort(points.begin(),points.end(),sortY);
    for (int i=0; i<n; ++i) {
        points[i].y = i+1; 
    }
    sort(points.begin(), points.end());
    for (int i=0; i<n; ++i) {
        points[i].x = i+1; 
        psums[points[i].x][points[i].y] = 1;
    }
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            psums[i][j] = psums[i][j-1] + psums[i-1][j] - psums[i-1][j-1] + (psums[i][j]);
        }
    }
    ll ans = 1; //the empty subset
    for (int i=0; i<points.size(); ++i) {
        int x1 = points[i].x; 
        int y1 = points[i].y;
        for (int j=i; j<points.size(); ++j){
            int x2 = points[j].x;
            int y2 = points[j].y;
            int c = max(x1,x2); int d = max(y1,y2); // top right grid
            int a = min(x1,x2); int b = min(y1,y2); //bottom left grid
            int points_abv = psums[c][n] - psums[a-1][n] - psums[c][d-1] + psums[a-1][d-1];
            int points_blw = psums[c][b] - psums[a-1][b] - psums[c][1-1] + psums[a-1][1-1];
            int poss = points_blw * points_abv;
            ans += poss;
        }
    }
    cout << ans;
}   