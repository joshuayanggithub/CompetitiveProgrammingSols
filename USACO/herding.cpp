#include <bits/stdc++.h>
using namespace std;

int n;
int c[100001];
int l,r, cowi, cows;
int mi = INT_MAX;
int ma;

void range() {
    while (cowi+1 < n && c[cowi+1] <= r) { //calculating #cows in this n-range
        ++cowi;
        ++cows;
    }
    int holes = n-cows;
    mi = min(mi,holes);
}
int main() {
    freopen("herding.in","r",stdin);
    freopen("herding.out","w",stdout);

    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> c[i];
    }
    sort(c,c+n);
    for (int i=c[0]; i<c[0]+n; ++i) {
        if (c[l] == i) {
            ++cows;
            ++l;
        }
    }
    cowi = cows-1;
    if (c[n-2]-c[0] == n-2 && c[n-1] - c[n-2] > 2) {
        mi = 2;
    }
    else if (c[n-1] - c[1] == n-2 && c[1] - c[0] > 2) {
        mi =2;
    }
    else {
        for (int i=0; i<n; ++i) {
        l = c[i];
        r = c[i]+n-1;
        if (r > c[n-1]) {
            break;
        }
        range();
        --cows;
        }
    }
    ma =max(c[n-2]-c[0], c[n-1]-c[1]) - (n-2);
    cout << mi << "\n" << ma;
}