#include <bits/stdc++.h>
using namespace std;

struct Move {
    int i,j;
    char c;
};

int n;
Move grid[75][75];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void dfs(int x, int y, int num) {
    if (num == 9) {
        return;
    }
    for (int d=0; d<4; ++d) {
        int newx = x + dx[d];
        int newy = y + dy[d];
        if (newx >= 0 && newx<n && newy>=0 && newy<n && grid[newx][newy].c != '#') {
            if (grid[newx][newy].c == '.' || grid[newx][newy].c == 'B') {
                dfs(newx,newy,num);
            }
            else if (grid[newx][newy].c == 'O' || grid[newx][newy].c == 'M') {
                place(newx,newy);
                dfs(newx,newy,num+1);
            }
        }
    }
}
void place(int x, int y) {
    
}
int main() {
    cin >> n;
    int starti,startj;
    for (int i=0; i<n; ++i) {
        string s; cin >> s;
        for (int j=0; j<n; ++j) {
            grid[i][j].c = s[3*j];
            if (s[3*j] == 'O' || s[3*j] == 'M' || s[3*j] == 'B') {
                grid[i][j].i =  s[3*j+1];
                grid[i][j].j = s[3*j+2];
            }
            if (s[3*j] == 'B') {
                starti = i;
                startj = j;
            }
        }
    }
    dfs(starti,startj,0);

}