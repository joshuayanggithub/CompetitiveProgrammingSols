#include <bits/stdc++.h>
using namespace std;

int n,t,q;

int main() {
    //cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> q;
        vector<int> fighters(n+1);
        int stopind = 0; //the round WHEN the biggest fighter wins
        int biggest = 0;
        for (int i=1; i<=n; ++i) {
            cin >> fighters[i];
            if (fighters[i] == n) {
                stopind = max(1,i-1); //round 1 edge case
                biggest = i;
            }
        }
        int p1 = 1, p2 = 2;
        vector<int> fwon(n+1);
        vector<array<int,4>> ans(q);
        for (int i=0; i<q; ++i) {
            cin >> ans[i][1] >> ans[i][0]; //round, ind
            ans[i][2] = i;
        }
        sort(ans.begin(),ans.end());
        int pround = 0;
        for (int i=1; i<=stopind; ++i) { //stopind fight number
            if (fighters[p1] > fighters[p2]) {
                fwon[p1]++;
                p2 = max(p1,p2)+1;
            }
            else {
                fwon[p2]++;
                p1 = max(p1,p2)+1;
            }
            while (ans[pround][0] == i) {
                ans[pround][3] = fwon[ans[pround][1]];
                ++pround;
            }
        }
        for (int i=0; i<q; ++i) {
            if (ans[i][1] == biggest && ans[i][0] > stopind) {
                ans[i][3] = fwon[ans[i][1]] + max(0,ans[i][0] - stopind);
            }
            if (ans[i][1] != biggest && ans[i][0] > stopind) {
                ans[i][3] = fwon[ans[i][1]];
            }
            int temp = ans[i][0];
            ans[i][0] = ans[i][2];
            ans[i][2] = temp;
        }
        sort(ans.begin(),ans.end());
        for (int i=0; i<q; ++i) {
            cout << ans[i][3] << "\n";
        }
    }
}

/*
3
3 1
3 1 2
1 2
4 2
1 3 4 2
4 5
3 2
5 2
1 2 3 5 4
5 1000000000
4 6
*/