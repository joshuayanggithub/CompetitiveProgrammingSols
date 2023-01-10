#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int t,n;
const int MAXN = 10;
int vis[MAXN][2];
char board[MAXN][2];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<pair<int,int>> rightmost;
vector<pair<int,int>> leftmost;

int size_ =0;

void dfs(int x, int y, int g) {
    ++size_;
    vis[x][y] = g;
    if (x > rightmost[g-1].f) {
        rightmost[g-1].f = x;
        rightmost[g-1].s = y;
    }
    else if (x == rightmost[g-1].f && y != rightmost[g-1].s) {
        rightmost[g-1].s = 2;
    }
    if (x < leftmost[g-1].f) {
        leftmost[g-1].f = x;
        leftmost[g-1].s = y;
    }
    else if (x == leftmost[g-1].f && y != leftmost[g-1].s) {
        leftmost[g-1].s = 2;
    }
    for (int i=0; i<4; ++i) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        if (newx >=0 && newx <n && newy>=0 && newy<2 && !vis[newx][newy] && board[newx][newy] == '*') {
            dfs(newx,newy,g);
        }
    }
}
void solve() {
    int ans =0;
    cin >> n;
    for (int i=0; i<2; ++i) {
        string s; 
        cin >> s;
        for (int j=0; j<n; ++j) {
            board[j][i] = s[j];
        }
    }
    int g = 1;
    for (int i=0; i<n; ++i) {
        for (int j=0; j<2; ++j) {
            if (vis[i][j] == 0 && board[i][j] == '*') {
                rightmost.push_back({-1,-1});
                leftmost.push_back({MAXN+1,MAXN+1});
                dfs(i,j,g);
                ans += size_-1;
                size_ = 0; //reset
                ++g;
            }
        }
    }
    int up,down = 0;
    for (int i=0; i<rightmost.size()-1; ++i) {
        ans += abs(leftmost[i+1].f-rightmost[i].f);
    }
    int lateradd =0;
    for (int i=1; i<rightmost.size()-1; ++i) {
        if ((rightmost[i].s == 0 && leftmost[i].s == 1) || (rightmost[i].s == 1 && leftmost[i].s == 0) ){
            lateradd++;
        }
        else if (rightmost[i].s == 0 && leftmost[i].s == 0) {
            up += 2;
        }
        else if ((rightmost[i].s == 1 && leftmost[i].s == 1)){
            down += 2;
        }
        if (rightmost[i].s == 1 && leftmost[i].s == 2) {
            ++down;
        }
        else if (rightmost[i].s == 0 && leftmost[i].s == 2) {
            ++up;
        }
        if (leftmost[i].s == 1 && rightmost[i].s == 2) {
            ++up;
        }
        else if (leftmost[i].s == 0 && rightmost[i].s == 2) {
            ++down;
        }
    }
    if (rightmost[0].s == 0) {
        ++up;
    }
    else if (rightmost[0].s == 1) {
        ++down;
    }
     if (leftmost[rightmost.size()-1].s == 0) {
        ++up;
    }
    else if (leftmost[rightmost.size()-1].s == 1) {
        ++down;
    }
    if (rightmost.size() > 1) {
        ans += min(up,down);
        ans += lateradd;
    }
    cout << ans << "\n";
    //reset everything!
    for (int i=0; i<n; ++i) {
        vis[i][0] = 0;
        vis[i][1] = 0;
    }
    rightmost.clear();
    leftmost.clear();
}
int main() {
    cin >> t;
    while (t--) {
        solve();
    }
}