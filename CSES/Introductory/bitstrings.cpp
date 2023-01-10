#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    cin >> n;
    int ans = 1;
    while (n--) {
        ans *= 2; ans %= int (1e9+7);
    }
    cout << ans;
}