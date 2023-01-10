#include <bits/stdc++.h>
using namespace std;

int n,m;
const int maxM = 2e5+1;
int lg[maxM+1]; //floor log precomp
vector<int> col(maxM);
int st[26][maxM]; //goofy sparse table
int xs,ys,xf,yf,k;

void solve() {
    cin >> xs >> ys >> xf >> yf >> k;
    if (abs(xs-xf)%k != 0 || abs(ys-yf)%k != 0) {
        cout << "NO\n";
        return;
    }
    if (yf < ys) { swap(yf,ys);}
    int maxrow = xs + (n-xs)/k*k;
    int maxlog = lg[abs(ys-yf)];
    int maxpow = pow(2,maxlog);
    int highestblocked = max(st[maxlog][ys],st[maxlog][yf-maxpow+1]);
    if (maxrow > highestblocked) {
        cout << "YES\n";
    }
    else 
        cout << "NO\n";
}

int main() {
    #ifdef LOCAL
        freopen("aa.in","r",stdin);
    #endif
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n >> m;
    lg[1] = 0;
    for (int i = 2; i <= maxM; i++)
        lg[i] = lg[i/2] + 1;
    for (int i=1; i<=m; ++i) {
        cin >> col[i];
    }
    for (int i=1; i<=m; ++i) {st[0][i] = col[i];}
    for (int i=1; i<=25; ++i) {
        for (int j=1; (j+(1<<i)-1)<=m; ++j) {
            st[i][j] = max(st[i-1][j], st[i-1][j+(1<<(i-1))]);
        }
    }
    int q; cin >> q;
    while (q--) {
        solve();
    }
}