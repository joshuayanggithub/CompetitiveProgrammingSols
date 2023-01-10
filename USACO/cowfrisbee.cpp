#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int h[n];
    for (int i=0; i<n; ++i) {
        cin >> h[i];
    }
    long long ans = 0;
    bool decreasing = false;
    vector<int> highpoints;
    int range[n];
    for (int i=0; i<n; ++i) {
        if (i==0) {
            if (h[i] > h[i+1])
                range[i] = 2;
            else
                range[i] = -2;
        }
        else if (i== n-1) {
            if (h[i] > h[i-1])
                range[i] = 2;
            else
                range[i] = -2;
        }
        else {
            if (h[i] > h[i-1] && h[i] > h[i+1]) {
                range[i] = 2;
            }
            else if (h[i] < h[i-1] && h[i] < h[i+1]) {
                range[i] = -2;
            }
            else if (h[i] < h[i-1] && h[i] > h[i+1]) {
                range[i] = -1;
            }
            else {
                range[i] = 1;
            }
        }
    }
    long long ans =0;
    for (int i=1; i<n; ++i) {
       if (range[i] < 0) { //decreasing
            ans += 1;
       }
       else if (range[i] == 1) {
           auto it = lower_bound(highpoints.begin(), highpoints.end(),h[i]);
       }
       if (range[i] == 2) {
            highpoints.push_back(i);
        }
    }
    cout << ans;
}