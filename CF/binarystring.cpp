#include <bits/stdc++.h>
using namespace std;

int t;
string s;

void solve() {
    cin >> s;
    s = '0' + s + '0';
    vector<int> ones(s.length()+1);
    vector<int> zeroind;
    for (int i=0; i<s.length(); ++i) {
        ones[i+1] = ones[i];
        if (s[i] == '0') {
            zeroind.push_back(i);
        }
        else {
            ones[i+1]++;
        }
    }
    int l=0, mid=0;
    int r = zeroind.size()-2;
    //int r = zeroind.size();
    while (l < r) {
        mid = (l+r-1)/2;
        bool works = false;
        for (int i=0; i<=zeroind.size()-mid-2; ++i) { //extra mid
        //for (int i=0; i<=zeroind.size()-mid; ++i) { //extra mid
            int lzero = zeroind[i]; //actual pos
            int rzero = zeroind[i+mid+2-1];
            //int rzero = zeroind[i+mid-1];
            lzero += 1;
            rzero -= 1;
            int numones = ones[lzero-1+1] + (ones[s.length()] - ones[rzero+1]);
            if (numones <= mid) {
                works = true;
                break;
            }
        }
        if (works) {
            r = mid;
        }
        else {
            l = mid+1;
        }
    }
    cout << l << "\n";
}   
int main() {
    cin >> t;
    while (t--) {
        solve();
    }
}


/*
5
101110110
1001001001001
0000111111
00000
1111
*/