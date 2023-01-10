#include <bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;
    string s,t;
    cin >> s; cin >> t;
    vector<int> a1,a2,c1,c2;
    string s2,t2;
    for (int i=0; i<n; ++i) {
        if (s[i] == 'a') {
            a1.push_back(i);
            s2 += 'a';
        }
        else if (s[i] == 'c') {
            c1.push_back(i);
            s2 += 'c';
        }
        if (t[i] == 'a') {
            a2.push_back(i);
            t2 += 'a';
        }
        else if (t[i] == 'c') {
            c2.push_back(i);
            t2 += 'c';
        }
    }
    if (!(a1.size() == a2.size() && c2.size() == c1.size()) || s2 != t2) {
        cout << "NO\n";
        return;
    }   
    //reverse(c1.begin(),c1.end());
    //reverse(c2.begin(),c2.end());
    for (int i=0; i<a1.size(); ++i) {
        if (a1[i] > a2[i]) {
            cout << "NO\n";
            return;
        }
    }
    for (int i=0; i<c1.size(); ++i) {
        if (c1[i] < c2[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}