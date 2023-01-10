#include <bits/stdc++.h>
using namespace std;

const unsigned long long maxn = (unsigned long long) 10e18 + 1;

int main() {
    int n; 
    cin >> n;
    for (int j=0; j<n; ++j) {
        long long p1,p2;
        cin >> p1 >> p2;
        long long ans = 100000;
        set<long long> p1s;
        set<long long> p2s;
        map<long long,long long> p1m;
        map<long long,long long> p2m;
        long long temp = p1;
        long long counter =0;
        while (temp > 0) {
            p1s.insert(temp);
            p1m[temp] = counter;
            if (temp%2 == 1 && temp != 1) {
                ++temp;
            }
            else {
                temp /= 2;
            }
            ++counter;
        }
        temp = p2;
        counter = 0;
        while (temp > 0) {
            p2s.insert(temp);
            p2m[temp] = counter;
            if (temp%2 == 1 && temp != 1) {
                --temp;
            }
            else {
                temp /= 2;
            }
            ++counter;
        }
        for (auto next: p1s) {
            auto it = lower_bound(p2s.begin(), p2s.end(),next);
            long long ab = *it;
            if (*it >= 0 && *it >= next && it != p2s.end()) {
                ans = min(ans,p1m[next]+p2m[*it]+(*it-next) );
            }
        }
        cout << ans << "\n";
    }
}