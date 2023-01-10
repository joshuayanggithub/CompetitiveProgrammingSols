#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int ans = 0;
    for (int i=0; i<n; ++i) {
        int a; cin >> a;
        int temp = a;
        int num = 0;
        while (temp > 0) {
            int dig = temp%10;
            if (dig == 4 || dig == 7) {
                ++num;
            }
            temp /= 10;
        }
        if (num <=k) {
            ++ans;
        }
    }
    cout << ans;
}