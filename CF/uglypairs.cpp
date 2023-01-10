#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int j=0; j<t; ++j) {
        string s;
        cin >> s;
        map <char, int> letters;
        string shortened = "";
        for (int i=0; i<s.length(); ++i) {
            char c = s[i];
            if (letters.count(c) >= 1) {
                letters[c] = letters[c] + 1;
            }
            else {
                letters[c] = 1;
                shortened += c;
            }
        }
        sort(shortened.begin(), shortened.end());
        string ret = "";
        string combined = "";
        if (letters.size() == 1) {
            combined = shortened;
        }
        else if (letters.size() == 2) {
            char a = shortened[0];
            char b = shortened[1];
            if ( int(b) == int(a) + 1) {
                ret = "No answer";
            }
            else {
                combined  = shortened;
            }
        }
        else if (letters.size() == 3) {
            char a = shortened[0];
            char b = shortened[1];
            char c = shortened[2];
            if ( int(b) == int(a) + 1 && int(c) != int(b) + 1 ) {
                combined+=a;
                combined+=c;
                combined+=b;
            }
            else if ( int(b) != int(a) + 1 && int(c) == int(b) + 1 ) {
                combined+=c;
                combined+=a;
                combined+=b;
            }
            else if ( int(b) == int(a) + 1 && int(c) == int(b) + 1 ){
                ret = "No answer";
            }
            else {
                combined = shortened;
            }
        }
        else {
            string odds = "";
            string evens = "";
            for (int i=0; i<shortened.length(); ++i) {
                if (i%2 == 0) {
                    odds += shortened[i];
                }
                else {  
                    evens += shortened[i];
                }
            }
            combined = evens + odds;
        }
        if (ret != "No answer") {
            for (int i=0; i<combined.length(); ++i) {
                for (int t =0; t<letters[combined[i]]; ++t) {
                    ret += combined[i];
                }
            }   
        }
        cout << ret << "\n";
    }
}