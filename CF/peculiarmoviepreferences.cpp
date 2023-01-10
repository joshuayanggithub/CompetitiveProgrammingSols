#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin >> n;
        map<string, int> m;
        map<string, int> three;
        bool yes = false;
        string a[n];
        for (int i=0; i<n; ++i) {
            cin >> a[i];
        }
        for (int i=0; i<n; ++i) {
            string s = a[i];
            if (s.length() == 1) {
                yes = true;
                break;
            }
            else if (s.length() == 2) {
                m[s]++;
                swap(s[0],s[1]); //reverse
                if (m.count(s) || three.count(s) || s[0] == s[1]) {
                    yes = true;
                    break;
                }
            }
            else {
                m[s]++;
                three[s.substr(0,2)]++; //first two
                string r = s;
                swap(r[0],r[2]);
                if (m.count(r) || m.count(r.substr(0,2)) || s[0] == s[2]) {
                    yes = true;
                    break;
                }
            }
        }
        if (yes) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
        cout << "\n";
    }
}