#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

void solve() {
    int n; 
    cin >> n;
    vector<int> a(n);
    int maxdig = 0;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        maxdig = max(maxdig, (int) log2(a[i]+1));
    }
    vector<int> vis(n);
    vector<int> o(a);
    int numzero = n;
    vector<int> extra;
    while (numzero != 0) {
        int maxnum = -1;
        int maxind = 0;
        //int bnum = 1<<b;
        for (int i=0; i<n; ++i) {
            //a[i] = ((a[i])&(bnum));
            if (a[i] > maxnum) {
                maxnum = a[i];
                maxind = i;
            }
        }
        cout << o[maxind] << " ";
        vis[maxind] = true;
        --numzero;
        for (int i=0; i<n; ++i) {
            int maxbit = log2(a[i]);
            int newnum = 0;
            for (int j=0; j<=maxbit; ++j) {
                int cur1 = (1<<j) & (a[i]);
                int cur2 = (1<<j) & maxnum;
                if (cur1 != 0 && cur2 == 0) {
                    newnum += (1<<j);
                }
            }
            a[i] = newnum;
            if (a[i] == 0 && !vis[i]) {
                --numzero;
                extra.push_back(i);
                vis[i] = true;
            }
        }
    }
    for (int i=0; i<extra.size(); ++i) {
        cout << o[extra[i]] << " ";
    }
    cout << endl;
}

/*
5
4
1 2 4 8
7
5 1 2 3 4 5 5
2
1 101
6
2 3 4 2 3 4
8
1 4 2 3 4 5 7 1

*/
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}