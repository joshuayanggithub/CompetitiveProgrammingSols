#include <bits/stdc++.h>
using namespace std;

int lessf(long long p1, long long p2) {
    long long ans = 0;
     while (p2/2 >= p1) {
        if (p2%2 == 1) {
            --p2;
            ++ans;
        }
        p2 /= 2;
        ++ans;
    }
    ans += p2-p1;
    return ans;
}
int more(long long p1, long long p2) {
    long long ans  = 0;
    while (p1 >= p2) {
        if (p1%2 == 1) {
            ++p1;
            ++ans;
        }
        p1 /= 2;
        ++ans;
    }
    if (p1 < p2) {
        ans += lessf(p1,p2);
    }
    return ans;
}
int main() {
    int n; 
    cin >> n;
    for (int i=0; i<n; ++i) {
        long long p1,p2;
        cin >> p1 >> p2;
        long long ans = 0;
        if (p1 < p2) {
            ans += lessf(p1,p2);
        }
        else if (p1 > p2) {
            ans += more(p1,p2);
        }
        cout << ans << "\n";
    }
}