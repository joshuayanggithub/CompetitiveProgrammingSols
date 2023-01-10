#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    vector<int> osums(s.length());
    vector<int> wsums(s.length());
    vector<int> csums(s.length());
    for (int i=1; i<=s.length(); ++i) {
        osums[i] = osums[i-1] + (s[i-1] == 'O');
        wsums[i] = wsums[i-1] + (s[i-1] == 'W');
        csums[i] = csums[i-1] + (s[i-1] == 'C');
        //cout << owsums[i];
    }
    int q; 
    cin >> q;
    for (int i=0; i<q; ++i) {
        int l,r; 
        cin >> l >> r;
        int o = osums[r] - osums[l-1];
        int w = wsums[r] - wsums[l-1];
        int c = csums[r] - csums[l-1];
        o %= 2; w %=2; c %=2;
        o += c;
        w += c;
        o %= 2; w %=2;
        if (o == 1 && w == 1) {
            cout << "Y";
        }
        else {
            cout << "N";
        }
    }
}

/*
COW
6
1 1
1 2
1 3
2 2
2 3
3 3
*/