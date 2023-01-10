#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    freopen("text.in","r",stdin);
    cin >> s;
    s = "." + s; //1 index everything

    vector<int> owsums(s.length());
    vector<int> csums(s.length());
    int ind_map[s.length()];
    int ind_map2[s.length()];
    vector<pair<int,int>> samelens;
    int red_ind = 0;
    string reds = "";
    int pointer = 1, cur =1;
    while (cur < s.length()) {
        while (pointer < s.length() && s[pointer] == s[cur]) {
            ++pointer;
        }
        int lastsame = pointer-1;
        samelens.push_back({cur,lastsame});
        if ((lastsame - cur + 1) % 2 ==1) {
            reds += s[cur];
        }
        for (int i=cur; i<=lastsame; ++i) {
            ind_map[i] = samelens.size()-1;
            ind_map2[i] = reds.length()-1;
        }
        cur = pointer;
    }
    for (int i=1; i<=reds.length(); ++i) {
        owsums[i] = owsums[i-1] + (reds[i-1] == 'W' || reds[i-1] == 'O' );
        csums[i] = csums[i-1] + (reds[i-1] == 'C');
        //cout << owsums[i];
    }
    int q; 
    cin >> q;
    for (int i=0; i<q; ++i) {
        int l,r; 
        cin >> l >> r;
        int r2 = ind_map2[r]+1; //prefix sum
        int l2 = ind_map2[l]+1;
        int ow = (owsums[r2]-owsums[l2-1]);
        int c = (csums[r2]-csums[l2-1]);

        int act_l = samelens[ind_map[l]].second - l + 1;
        int act_r = r - samelens[ind_map[r]].first + 1;
        int tl = 0, tr = 0;
        if (act_l % 2 == 1) {
            tl = 1;
        }
        if (act_r % 2 == 1) {
            tr = 1;
        } 
        int thought = 0;
        if ((samelens[ind_map[l]].second - samelens[ind_map[l]].first + 1) % 2 == 1) {
            thought = 1;
        }
        if (s[l] == 'O' || s[l] == 'W') {
            if (thought == 0 && tl == 1) {
                ow++;
            } 
            else if (thought == 1 && tl == 0) {
                ow--;
            }
        }
        else {
            if (thought == 0 && tl == 1) {
                c++;
            } 
            else if (thought == 1 && tl == 0) {
                c--;
            }
        }
        thought = 0;
        if ((samelens[ind_map[r]].second - samelens[ind_map[r]].first + 1) % 2 == 1) {
            thought = 1;
        }
        if (s[r] == 'O' || s[r] == 'W') {
            if (thought == 0 && tr == 1) {
                ow++;
            } 
            else if (thought == 1 && tr == 0) {
                ow--;
            }
        }
        else {
            if (thought == 0 && tr == 1) {
                c++;
            } 
            else if (thought == 1 && tr == 0) {
                c--;
            }
        }
        if ( (ow  + c*2)%4 == 2) {
            cout << "Y";
        }
        else {
            cout << "N";
        }
    }
}

/*
COW
6
1 1
1 2
1 3
2 2
2 3
3 3
*/