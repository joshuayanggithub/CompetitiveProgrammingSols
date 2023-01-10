#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin >> s;
    map<char,int> m;
    for (int i=0; i<s.length(); ++i) {
        m[s[i]]++;
    }
    string ans = "";
    char odd='a';
    for (auto&[a,b]: m) {
        if (b%2 == 1) {
            if (odd!='a') {
                cout << "NO SOLUTION"; 
                return 0;
            }
            odd = a;
        }
        else {
            for (int i=0; i<b/2; ++i) {
                ans += a;
            }
        }
    }
    if (odd!='a') {
        for (int i=0; i<(m[odd]+1)/2; ++i) {
                ans += odd;
            }
    }
    for (int i= (odd!='a')?ans.length()-2: ans.length()-1; i>=0; --i) {
        ans += ans[i];
    }
    cout << ans;
}