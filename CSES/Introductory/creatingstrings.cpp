#include <bits/stdc++.h>
using namespace std;

string s;
set<string> ans;

void permute(string p, int n) {
    if (p.length() == s.length()) {
        ans.insert(p);
        return;
    }
    for (int i=0; i<s.length(); ++i) {
        if ((n & (1<<i)) == 0) {
            permute(p+s[i],n+(1<<i));
        }
    }
}
int main() {
    cin >> s;
    sort(s.begin(),s.end());
    permute("",0);
    cout << ans.size() << "\n";
    for (auto& str: ans) {
        cout << str << "\n";
    }
}