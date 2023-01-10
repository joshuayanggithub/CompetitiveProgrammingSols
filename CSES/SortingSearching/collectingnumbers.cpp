#include <bits/stdc++.h>
using namespace std;

int n, cur, ans;
int m[(int) 2e5+1];

int main() {
    cin >> n;
    for (int i=0; i<n; ++i) {
        int temp; cin >> temp;
        m[temp] = i;
    }
    for (int i=1; i<=n; ++i) {
        if (m[i] < m[i-1])
            ++ans;
    }
    cout << ans+1;
}