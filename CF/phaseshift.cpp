#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> letters(26);
vector<int> len(26);
vector<int> link(26);

int find(int x) {
    while (x != link[x]) {
        x = link[x];
    }
    return x;
}

bool same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    int rep1 = find(a);
    int rep2 = find(b);
    if (len[rep1] > len[rep2]) 
        swap(rep1,rep2);
    len[rep2] += len[rep1];
    link[rep1] = rep2;
}

int ascii(char c) {
    return c - 97;
}

void solve() {
    cin >> n;
    vector<char> fromletter(26);
    vector<char> toletter(26);
    string t; cin >> t;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for (int i=0; i<26; ++i) {
        link[i] = i;
        len[i] = 1;
    }
    string ans = "";
    for (int i=0; i<t.length(); ++i) {
        if (alphabet.length() == 0 || toletter[ascii(t[i])]) {
            //cout << toletter[ascii(t[i])];
            ans += toletter[ascii(t[i])];
            continue;
        }
        int smallest = alphabet[0];
        int smallest_ind = 0;
        while (alphabet.length() != 1 && same( ascii(t[i]) ,ascii(smallest))) { //same connected component its also not possible
             smallest_ind++;
             smallest = alphabet[smallest_ind];
        }
        fromletter[ascii(smallest)] = t[i];
        toletter[ascii(t[i])] = smallest;
        ans += toletter[ascii(t[i])];
        unite(ascii(smallest),ascii(t[i]));
        for (int j=0; j<alphabet.length(); ++j) {
            if (alphabet[j] == smallest) {
                alphabet.erase(j,1);
                break;
            }
        }
    }

    cout << ans << endl;
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}