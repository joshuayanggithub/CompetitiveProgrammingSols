#include <bits/stdc++.h>
using namespace std;

int n;
const int mxN = 17;
vector<string> v[mxN];
void bitstring(string s, int x) {
    if (x==0) {
        v[x].push_back("");
        return;
    }
    bitstring(s,x-1);
    for (int i=0; i<v[x-1].size(); ++i) {
        v[x].push_back("0" + v[x-1][i]);
    }
     for (int i=v[x-1].size()-1; i>=0; --i) {
        v[x].push_back("1" + v[x-1][i]);
    }
}

int main() {
    cin >> n;
    bitstring("",n);
    for (int i=0; i<v[n].size(); ++i) {
        cout << v[n][i] << "\n";
    }
}