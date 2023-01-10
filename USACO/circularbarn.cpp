#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e6+1;
//set<int> ez;

bool oneMove(int n) { //includes 1
    for (int i=2; i*i<=n; ++i) {
        if (n%i == 0) {
            return false;
        }
    }
    return true;
}
void solve() {
    int n; cin >> n;
    vector<int> v(n);
    vector<int> moves(n);
    for (int i=0; i<n; ++i) {
        cin >> v[i];
        if (oneMove(v[i])) {
            moves[i] = 1;
        }
        else if (v[i]%2 == 0) {
            moves[i] = v[i]/2;
            moves[i] = (moves[i]%2 == 0) ? moves[i]/2+1 : (moves[i]+1)/2;
        }
        else {
            int it = 1;
            while(!oneMove((moves[i]-4*it))) {
                it++;
            }
            moves[i] = (it*4)/2+1;
            moves[i] = (moves[i]%2 == 0) ? moves[i]/2+1 : (moves[i]+1)/2;
        }
    }
    int mi = 0;
    for (int i=0; i<n; ++i) {
        if (moves[i] < moves[mi]) {
            mi = i;
        }
    } 
    if (v[mi]%4 == 0) {
        cout << "Farmer Nhoj\n";
    }
    else 
        cout << "Farmer John\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}