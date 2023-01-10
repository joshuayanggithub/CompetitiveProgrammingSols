#include <bits/stdc++.h>
using namespace std;

bool pairs[18][18];

int main() {
    string s,t;
    cin >> s >> t;
    int q;
    cin >> q;
    for (char c1 = 'a'; c1 <= 'r'; ++c1) {
        for (char c2 = c1; c2 <= 'r'; ++c2) {
            string s1 = "", s2 = "";
            for (int i=0; i<s.length(); ++i) {
                if (s[i] == c1 || s[i] == c2)
                    s1 += s[i];
            }
            for (int i=0; i<t.length(); ++i) {
                if (t[i] == c1 || t[i] == c2)
                    s2 += t[i];
            }
            if (s1 == s2) {
                pairs[c1-'a'][c2-'a'] = true;
            }
            else {
                pairs[c1-'a'][c2-'a'] = false;
            }
        }
    }
    for (int i=0; i<q; ++i) {
        string query; cin >> query;
        bool works = true;
        for (int j=0; j<query.length(); ++j) {
            for (int j2=j; j2<query.length(); ++j2) {
                if (!pairs[query[j]-'a'][query[j2]-'a']) {
                    works = false;
                    break;
                }
            }
        }
        if (works)
            cout << "Y";
        else 
            cout << "N";
    }
}