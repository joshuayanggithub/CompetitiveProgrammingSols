#include <bits/stdc++.h>
using namespace std;

void solve() {
    int m,n,k;
    cin >> m >> n >> k;
    //folders is simply 1 through n
    int emails[n+1];
    vector<int> lastocurr(n+1);
    for (int i=1; i<=n; ++i) {
        cin >> emails[i];
        lastocurr[emails[i]] = i; //if 0, then that means that folder's email number never occured
    }
    int lview =1;
    int rview =k; //view emails 1 to k currently
    int numfiled = 0;
    vector<bool> vis(n+1);
    vector<int> skipped; //emails to file to come back to
    int iskip = 0; //the index relating to that vector

    for (int f=1; f<=m-k+1; ++f) {
        //folder view is folder f to folder f+k-1
        int lfview = f;
        int rfview = f+k-1;
        int i = lview; //skipped[iskip];
        bool start = true;
        while (rview <= lastocurr[f]) {
            if (!start) {
                lview = max(lview+1,n);
                rview = max(rview+1,n);
            }
            start = false;
            while (i <= rview) { //iterate
                if (!vis[i] && emails[i] >= lfview && emails[i] <= rfview) {
                    vis[i] = true;
                    ++numfiled; //adjust view
                    if (i ==lview)
                        lview = max(lview+1,n);
                    if (rview == n)
                        lview = min(lview-1,1);
                    rview = max(rview+1,n);
                }
                else {
                    if (!vis[i])
                        skipped.push_back(i);
                }
                ++i;
            }
            if (rview == n) { //out of bounds
                break;
            }
        }
    }
    if (numfiled == n)
        cout << "YES\n";
    else 
        cout << "NO\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve(); //CF format
    }
}
/*
6
5 5 1
1 2 3 4 5
5 5 1
1 2 3 5 4
5 5 1
1 2 4 5 3
5 5 2
1 2 4 5 3
3 10 2
1 3 2 1 3 2 1 3 2 1
3 10 1
1 3 2 1 3 2 1 3 2 1
*/