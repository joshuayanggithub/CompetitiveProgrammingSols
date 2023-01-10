#include <bits/stdc++.h>
using namespace std;

//editorial
bool solve() {
    string s; cin >> s;
     int wh = 0, cnt = 0;
    for (char c : s) {
        if (c == '(')cnt++;
        if (c == ')')cnt--;
        if (c == '?')wh++;
        if (cnt + wh == 1) {
            cnt = 1;
            wh = 0;
        }
    }
    if (abs(cnt) == wh) return true;
    return false;
}
int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    int t;
    cin >> t;
    while (t--) {
        if (solve()) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << "\n";
    }
}