#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        int a[n];
        int b[n];
        for (int i=0; i<n; ++i) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b,b+n);
        vector<pair<int,int>> diff;
        diff.push_back({b[0],1});
        for (int i=1; i<n; ++i) {
            if (b[i] != b[i-1]) {
                diff.push_back({b[i],1});
            }
            else {
                diff[diff.size()-1].second++;
            }
        }
        int l = 0;
        int r= -1;
        int counter = 0;
        int m = diff.size();
        int yx = INT_MAX;
        int x,y;
        x = y = 0;
        while (l<m) {
            while (r<m) {
                if (counter >= (n-counter+k)) {
                    if (diff[r].first - diff[l].first < yx) {
                        yx = diff[r].first - diff[l].first;
                        x = diff[l].first; y = diff[r].first;
                    }
                    break;
                }
                ++r;
                counter += diff[r].second;
            }
            counter -= diff[l].second;
            ++l;
        }
        int sum = 0;
        int prev = 0;
        int s,e;
        s = e = 1;
        cout << x << " " << y << "\n";
        if (k == 1) {
            cout << 1 << " " << n << "\n";
            continue;
        }
        for (int i=0; i<n; ++i) {
            if (a[i] <= y && a[i] >= x) {
                ++sum;
            }
            else {
                --sum;
            }
            if (sum > prev) {
                prev = sum;
                e = i+1;
                cout << s << " " << e << "\n";
                s = e+1;
            }
            if (sum == k-1) {
                break;
            }
        }
        cout << s << " " << n << "\n";

    }
}