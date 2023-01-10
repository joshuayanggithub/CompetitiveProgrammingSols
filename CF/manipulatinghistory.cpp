#include <bits/stdc++.h>
using namespace std;

int t,n;

void solve() {
    string a[2*n+1];
    vector<int> letters(26);
    for (int i=0; i<2*n+1; ++i) {
        cin >> a[i];
        for (int j=0; j<a[i].length(); ++j) {
            letters[a[i][j]-97]++;
        }
    }
    for (int i=0; i<26; ++i) {
        if (letters[i]%2 == 1) {
            char c = i+97;
            cout << c << "\n";
        }
    }
}
int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        solve();
    }
}