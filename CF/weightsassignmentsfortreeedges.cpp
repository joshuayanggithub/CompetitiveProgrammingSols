#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int main() {
    int t = 0;
    cin >>t;
    for (int i=0; i<t; ++i) {
        int n = 1;
        cin >> n;
        vector<int> a (n+1,0);
        vector<int> w (n+1,0);
        vector<int > p (n+1);
        vector<int> totaldis (n+1,0);
        vector<bool> vis (n+1,0);
        int root = 0;
        for (int j=1; j<=n; ++j) {
            cin >> a[j];
            if (a[j] == j) {
                root =  j;
            }
        }
        for (int j=1; j<=n; ++j) {
            cin >> p[j];
        }
        bool possible = 1;
        if (root != p[1]) {
            possible = false;
        }
        for (int j=1; j<=n; ++j) {
            int previousdist = totaldis[p[j-1]]; //previous
            int node = p[j]; //current
            int ancestor = a[node];
            vis[node] = true;
            if (vis[ancestor] == true) { //been to ancestor yet
                totaldis[node] = previousdist + 1;
                if (node == root) {
                    totaldis[node] = 0;
                }
                w[node] = totaldis[node] - totaldis[ancestor]; //total dist - dist to ancestor
            }
            else {
                possible = false;
                break;
            }
        }
        cerr << "\n";
        if (possible == 0) {
            cout << -1 << "\n";
        }
        else {
            for (int j=1; j<=n; ++j) {
                cout << w[j] << " ";
            }
            cout << "\n";
        }
        cerr << "\n";
    }
}