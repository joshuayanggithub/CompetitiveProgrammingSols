#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n,a;

int main() {
    cin >> n;
    vector<ll> poss(1,0);
    ll closest = INT_MAX;
    ll ma= -1;
    for (int i=0; i<n; ++i) {
        cin >> a;
        for (int i=0, temp=poss.size(); i<temp; ++i) {
            ma=max(ma,poss[i]+a);
            poss.push_back(poss[i]+a);
        }
    }
    for (auto& num: poss) {
        closest = min((ll)abs((ma-num)-num),closest);
    }
    cout << closest;
}