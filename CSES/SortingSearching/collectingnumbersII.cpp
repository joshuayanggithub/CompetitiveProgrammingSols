#include <bits/stdc++.h>
using namespace std;

int n,m, cur, ans=1;
int pos[(int) 2e5+1];
int v[(int) 2e5+1];

int main() {
    //freopen("e.in","r",stdin);
    cin >> n >> m;
    for (int i=1; i<=n; ++i) {
        cin >> v[i];
        pos[v[i]] = i;
    }
    for (int i=1; i<=n; ++i) {
        if (pos[i] < pos[i-1])
            ++ans;
    }
    for (int i=0; i<m; ++i) {
        int a,b; cin >> a >> b;
        int na=v[a],nb=v[b];
        int pab=pos[na-1],paf=pos[na+1],pbb=pos[nb-1],pbf=pos[nb+1];
        swap(pos[na],pos[nb]);      
        if (a < pab && b>pos[na-1])
            --ans;
        if (a > paf && b<pos[na+1])
            --ans;
        if (a > pab && b<pos[na-1])
            ++ans;
        if (a < paf && b>pos[na+1])
            ++ans;
        if (nb-1 != na && b < pbb && a>pos[nb-1])
            --ans;
        if (nb+1 != na && b > pbf && a<pos[nb+1])
            --ans;
        if (nb-1 != na && b > pbb && a<pos[nb-1])
            ++ans;
        if (nb+1!=na && b < pbf && a>pos[nb+1])
            ++ans;
        swap(v[a],v[b]);
        cout << ans << "\n";
    }
}