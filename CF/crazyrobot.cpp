#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main() {
    int t;
    cin >> t;
    for (int j=0; j<t; ++j) {
        int n,m;
        cin >> n >> m;
        char cells [n][m];
        pair<int,int> labcoord;
        for (int r=0; r<n; ++r) {
            for (int c=0; c<m; ++c) {
               cin >> cells[r][c];
               if (cells[r][c] == 'L') {
                    labcoord.f = r; 
                    labcoord.s = c;
               }
            }
        }   
        queue<pair<int,int>> q;
        for (int i=0; i<4; ++i) {
            int newx = labcoord.f +dx[i];
            int newy = labcoord.s + dy[i];
            if (newx >=0 && newx <n && newy>=0 && newy<m && cells[newx][newy] == '.') {
                q.push({newx,newy});
            }
        }
        while (!q.empty()) {
            int xc = q.front().f; 
            int yc = q.front().s;
            q.pop();
            int free = 0;
            int freex = 0;
            int freey = 0;
            for (int i=0; i<4; ++i) {
                int newx = xc +dx[i];
                int newy = yc + dy[i];
                if (newx >=0 && newx <n && newy>=0 && newy<m) {
                    if (cells[newx][newy] == '.') {
                        ++free;
                        freex = newx;
                        freey = newy;
                    }
                }
            }
            if (free == 1) {
                cells[xc][yc] = '+';
                q.push({freex, freey});
            }
            else if (free == 0) { //not on 'L';
                cells[xc][yc] = '+';
                //q.push({xc, yc});
            }
        }
        for (int r=0; r<n; ++r) {
            for (int c=0; c<m; ++c) {
                cout << cells[r][c];
            }
            cout << "\n";
        }
    }
}