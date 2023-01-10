#include <bits/stdc++.h>
using namespace std;
#define ll long long

string s;
int p,ans=1;

int main() {
    cin >> s;
    while (p<s.length()-1) {
        int count=1;
        while (s[p] == s[p+1]) {
            ++p;
            ++count;
        }
        ++p;
        ans = max(ans, count);
    }
    cout << ans;
}