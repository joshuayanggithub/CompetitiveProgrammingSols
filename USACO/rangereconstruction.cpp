#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int diff[n+1][n+1];
    vector<int> offsets(n+1);
    for (int i=1; i<=n; ++i) {
        for (int j=i; j<=n; ++j) {
            cin >> diff[i][j];
        }  
    }
    for (int right=1; right<=n; ++right) {
        int p1=0,p2=0;
        bool chosen = false;
        for (int left=right-1; left>=1; --left) {
            int change = (diff[left][right] - diff[left][right-1]); //change from [left,right-1] to [left,right]
            if (left==right-1) {
                p1 = offsets[right-1] + change;
                p2 = offsets[right-1] - change;
            }
            int mi= offsets[left], ma = offsets[left];
            for (int i=left; i<=right-1; ++i) {
                mi = min(offsets[i],mi); ma = max(offsets[i],ma);
            }
            if (max(ma,p1)-min(mi,p1) == diff[left][right] && max(ma,p2)-min(mi,p2) != diff[left][right]) {
                chosen = true;
                offsets[right] = p1; break;
            }
            else if (max(ma,p1)-min(mi,p1) != diff[left][right] && max(ma,p2)-min(mi,p2) == diff[left][right]) {
                chosen = true;
                offsets[right] = p2; break;
            }
        }
        if (!chosen) {
            offsets[right] = p1;
        }
    }
    int mi=0,ma=0;
    int addtoall = 0;
    for (int i=1; i<=n; ++i) {
        mi = min(mi,offsets[i]);
        ma = max(ma,offsets[i]);
    }   
    if (mi<(int)(-1e9)) {
        addtoall = (int)(-1e9) - mi;
    }
    else if (ma>(int)1e9) {
        addtoall = -(ma - 1e9);
    }
    for (int i=1; i<=n; ++i) {
        cout << offsets[i] + addtoall << (i<n ? " " : "");
    }
}