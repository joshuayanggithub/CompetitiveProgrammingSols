/*
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

const int maxn = 10;
string s[maxn];
bool vis[maxn];

void compare(int l, int r, int n) {
    for (int i=0; i<50; ++i) { //every index 
        pair<string,int> c[r-l+1];
        for (int sind=0; sind<n; ++sind) { //which string
            if (i < s[sind].size()) {
                string ctostring (1,s[sind][i]); //string version
                c[sind] = { ctostring, sind};
            }
            else { //i >= size
                string ctostring (1,comparing[i-s[sind].length()]);
                c[sind] = {ctostring, sind};
            }
        }
        sort(c, c+n);
        int newc = 0;
        for (int j=1; j<n; ++j) {
            if (vis[j]) {
                continue;
            }
            if (c[j].f != c[j-1].f || j == n-1) {
                compare(newc,j-1); //range of values
                newc = j;
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> s[i];
    }
    string comparing = "";
    for (int i=0; i<50; ++i) { //every index 
        pair<string,int> c[n];
        for (int sind=0; sind<n; ++sind) { //which string
            if (i < s[sind].size()) {
                string ctostring (1,s[sind][i]); //string version
                c[sind] = { ctostring, sind};
            }
            else { //i >= size
                string ctostring (1,comparing[i-s[sind].length()]);
                c[sind] = {ctostring, sind};
            }
        }
        sort(c, c+n);
        int newc = 0;
        for (int j=1; j<n; ++j) {
            if (vis[j]) {
                continue;
            }
            if (c[j].f != c[j-1].f || j == n-1) {
                compare(newc,j-1); //range of values
                newc = j;
            }
        }
    }
}
*/