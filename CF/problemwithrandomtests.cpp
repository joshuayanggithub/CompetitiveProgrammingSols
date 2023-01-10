#include <bits/stdc++.h>
using namespace std;

int n;
string s;

string stringor(string a, string b) {
    int p1 = a.size()-1, p2 = b.size()-1;
    string ret = "";
    while (p1>=0 || p2>=0) {
        if (p1 > 0 && p2 <0) {
            ret += a[p1];
        }
        else if (p2 > 0 && p1 < 0) {
            ret += b[p2];
        }
        else {
            if (a[p1] == '1' || b[p2] == '1') {
                ret += "1";
            }
            else {
                ret += "0";
            }
        }
        --p1, --p2;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}
string remove0 (string a) {
    int p = 0;
    while (p<a.length()-1 && a[p] == '0') {
        ++p;
    }
    return a.substr(p,a.length()-p);
}
void solve() {
    cin >> n;
    cin >> s;
    s = remove0(s);
    n = s.length();
    //cout << s;
    int lastone = 0;
    for (int i=0; i<s.length(); ++i) {
        if (s[i] == '0') {
            lastone = i;
            break;
        }
    }
    string maxstr = "0";
    for (int i=0; i<=lastone; ++i) {
        string s2 = s.substr(0,s.length()-i);
        string conc = stringor(s,s2);
        if (conc > maxstr)
            maxstr = conc;
    }
    cout << maxstr << "\n";
}

int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    solve();
}