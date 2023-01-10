#include <bits/stdc++.h>
using namespace std;

int coords[1000][2];

int main() {
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> coords[i][0] >> coords[i][1]; 
    }
    int l=0; 
    int r=25000*25000*2+1;
    while (l<r) {
        int mid = (l+r-1)/2;
        vector<bool> vis(n);
        stack<int> q;
        q.push(0);
        int counter = 0; 
        while (!q.empty()) {
            int i = q.top(); q.pop();
            if (vis[i]) {
                continue;
            }
            vis[i] = true;
            ++counter;
            for (int j=0; j<n; ++j) {
                int dist = abs(coords[i][0] - coords[j][0]) * abs(coords[i][0] - coords[j][0])
                           + abs(coords[i][1] - coords[j][1]) * abs(coords[i][1] - coords[j][1]);
                if (dist <= mid && !vis[j]) {
                    //vis[j] = true;
                    q.push(j);
                }
            }
        }
        if (counter == n) {
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    cout << l;
}