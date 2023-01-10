#include <bits/stdc++.h>
using namespace std;

int n,k;
string s;

void solve() {
    cin >> n >> k;
    cin >> s;
    vector<int> occurences(26);
    int needadd=0;
    for (char&c: s) {
        occurences[c-'a']++;
    }
    for (int i=0; i<26; ++i) {
        needadd+= (k-occurences[i]%k)%k;
    }
    if (needadd==0) {
        cout << s << "\n";
        return;
    }
    string ans;
    for (int i=s.length()-1; i>=0; --i) {
         occurences[s[i]-'a']--;
        for (char c=s[i]+1; c<='z'; ++c) {
            needadd=0;
            occurences[c-'a']++;
            for (int i=0; i<26; ++i) {
                needadd+= (k-occurences[i]%k)%k;
            }
            int space = s.length()-1-i;
            if ( needadd <= space && (space- needadd)%k == 0) {
                ans = s.substr(0,i) + c;
                string ans2 = "";
                for (int j=0; j<26; ++j) {
                    int times = (k-occurences[j]%k)%k;
                    while (times--) {
                        ans2 += ('a'+j);
                    }
                }
                for (int add=0; add<(space-needadd); ++add) {
                    ans += ('a');
                }
                ans += ans2;
                cout << ans << "\n";
                return;
            }
            occurences[c-'a']--;
        }
    }
    cout << -1 << "\n";
}

int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    int t; cin >> t;
    while (t--) {
        solve();
    }
}