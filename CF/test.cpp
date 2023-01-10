#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "123";
    string s2 = "123323333";
    cout << s.length()-s2.length();
    for (int i=0; i<((int)s.length()-(int)s2.length()); ++i) {
        cout << "WTF";
    }
}