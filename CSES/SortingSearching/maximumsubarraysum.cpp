#include <bits/stdc++.h>
using namespace std;

int n;
long long sum,ans;

int main() {
    cin >> n;
    ans = -1e9;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        sum += a;
        ans = max(ans, sum);
        if (sum <0)
            sum = 0;
    }
    cout << ans;
}