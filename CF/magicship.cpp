#include <bits/stdc++.h>
using namespace std;

int main() {
    #define int long long
    int x1,y1,x2,y2;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x,y; x= y = 0;
    for (int i=0; i<n; ++i) {
        if (s[i] == 'U') {
            ++y;
        }
        else if (s[i] == 'D') {
            --y;
        }
        else if (s[i] == 'L') {
            --x;
        }
        else if (s[i] == 'R') {
            ++x;
        }
    }
    int l = 0;
    int r = 2e14+1;
    while (l<r) {
        int mid = (l+r-1)/2;
        int changex = (mid/n)*x;
        int changey = (mid/n)*y;
        int mod = mid%n;
        for (int i=0; i<mod; ++i) {
            if (s[i] == 'U') {
                ++changey;
            }
            else if (s[i] == 'D') {
                --changey;
            }
            else if (s[i] == 'L') {
                --changex;
            }
            else if (s[i] == 'R') {
                ++changex;
            }
        }
        int lr = abs(x2 - (x1+changex));
        int ud = abs(y2 - (y1+changey));
        if (mid >= lr + ud) {
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    if (l == 2e14+1) {
        cout << -1;
    }
    else {
        cout << l;
    }
}