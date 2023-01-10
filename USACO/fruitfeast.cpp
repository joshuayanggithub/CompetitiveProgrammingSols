#include <bits/stdc++.h>
using namespace std;

int t,a,b;
bool fullness[(int) 5e6+1][2];

int main() {
    freopen("feast.in","r",stdin);
    freopen("feast.out","w",stdout);
    cin >> t >> a >> b;
    fullness[0][0] = true;
    fullness[0][1] = true;
    for (int i=0; i<=t; ++i) {
        if (fullness[i][0] && !fullness[i/2][1]) {
            fullness[i/2][1] = true;
        }
        if (i+a <=t) {
            if (!fullness[i+a][0]) {
                fullness[i+a][0] = fullness[i][0];
            }
        }
        if (i+b <= t) {
            if (!fullness[i+b][0]) {
                fullness[i+b][0] = fullness[i][0];
            }
        }
        if (i+a+b <= t) {
            if (!fullness[i+a+b][0]) {
                fullness[i+a+b][0] = fullness[i][0];
            }
        }
    }
    for (int i=0; i<=t; ++i) {
        if (i+a <=t && !fullness[i+a][1]) {
            fullness[i+a][1] = fullness[i][1];
        }
        if (i+b <= t && !fullness[i+b][1]) {
            fullness[i+b][1] = fullness[i][1];
        }
        if (i+a+b <= t && !fullness[i+a+b][1]) {
            fullness[i+a+b][1] = fullness[i][1];
        }
    }
    for (int i=t; i>=0; --i) {
        if (fullness[i][0] || fullness[i][1]) {
            cout << i;
            break;
        }
    }

}