#include <bits/stdc++.h>
using namespace std;

const int mxN = 50;
bool vis[mxN][mxN];
int dx[] = {-1,0,1,0,1,-1};
int dy[] = {0,1,0,-1,1,-1};
char grid[mxN][mxN];
int n,m;
vector<pair<int,int>> cur;

void dfs(int x, int y) {
    vis[x][y] = true;
    cur.push_back({x,y});
    if (cur.size() >3)
        return;
    for (int i=-1; i<=1; ++i) {
        for (int j=-1; j<=1; ++j) { // 0 , 0 dont matter
            int nextx = x + i;
            int nexty = y + j;
            if (nextx < n && nextx >=0 && nexty < m && nexty >=0 && !vis[nextx][nexty] && grid[nextx][nexty] == '*') {
                dfs(nextx,nexty);
            }
        }
    }
}
void reset() {
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            vis[i][j] = false;
        }
    }
}
bool start_dfs() {
    bool works = true; //no asterisks edge case
    for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
            if (!vis[i][j] && grid[i][j] == '*') {
                dfs(i,j);
                if (cur.size() == 3) {
                    int minx = min({cur[0].first,cur[1].first,cur[2].first});
                    int maxx = max({cur[0].first,cur[1].first,cur[2].first});
                    int miny = min({cur[0].second,cur[1].second,cur[2].second});
                    int maxy = max({cur[0].second,cur[1].second,cur[2].second});
                    if (abs(minx-maxx) == 1 && abs(miny - maxy) == 1) {
                        works = true;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
                cur.clear();
            }
        }
    }
    return works;
}
int main() {
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                cin >> grid[i][j];
            }
        }
        bool works = start_dfs();
        cur.clear();
        reset();
        if (works)
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
}