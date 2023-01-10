#include <iostream>
#include <algorithm>
using namespace std;

struct Coord {
    int x,y;
};
bool sorty(const Coord& c1, const Coord& c2) {
    return c1.y < c2.y;
}
bool sortx(const Coord& c1, const Coord& c2) {
    return c1.x < c2.x;
}

const int maxn =2501;
int grid[maxn][maxn];

int main() {
    int n; 
    cin >> n;
    Coord points[n];
    for (int i=0; i<n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points,points+n,sortx);
    for (int i=0; i<n; ++i) {
        points[i].x = i+1;
    }
    sort(points,points+n,sorty);
    for (int i=0; i<n; ++i) {
        points[i].y = i+1;
    }
    for (int i=0; i<n; ++i) {
        grid[points[i].x][points[i].y] = 1;
    }
    long long ans =1;
    for (int i=1; i<=n; ++i) {
        for (int j=1; j<=n; ++j) {
            if (j != 0) {
                grid[i][j] += grid[i][j-1];
            }
            if (i != 0) {
                grid[i][j] += grid[i-1][j];
            }
            if (i!= 0 && j!= 0) {
                grid[i][j] -= grid[i-1][j-1];
            }
        }
    }
    
    for (int i=0; i<n; ++i) {
        for (int j=i; j<n; ++j) {
            int miny = min(points[i].y,points[j].y);
            int maxy = max(points[i].y,points[j].y);
            int minx = min(points[i].x,points[j].x);
            int maxx = max(points[i].x,points[j].x);
            int up = grid[maxx][miny] - grid[minx-1][miny];
            int down = grid[maxx][n] - grid[minx-1][n] -grid[maxx][maxy-1] + grid[minx-1][maxy-1];
            ans += (long long) up * (long long) down;
        }
    }
    cout << ans;
}