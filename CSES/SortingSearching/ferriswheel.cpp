#include <bits/stdc++.h>
using namespace std;

int n,x,p1,p2,ans;

int main() {
    cin >> n >> x;
    vector<int> children(n);
    for (int i=0; i<n; ++i) {cin >> children[i];}
    sort(children.begin(),children.end());
    p2 = n-1;
    while (p1<=p2) {
        if (children[p2]+children[p1]<=x) {
            ans++; p1++; p2--;
        }
        else if (children[p2]+children[p1] > x) {
            --p2; ++ans;
        }
    }
    cout << ans;
}