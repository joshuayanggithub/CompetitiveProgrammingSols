#include <bits/stdc++.h>
using namespace std;
 
 
//used editorial to solve :(
 
int main() {
    int n,k;
    cin >> n >> k;
    int arr[n];
    for (int i=0; i<n; ++i) {
        cin >> arr[i];
    }
    int l = 1;
    int r = n;
    while (l<r) {
        int mid = (l+r+1)/2;
        int a[n];
        for (int i=0; i<n; ++i) {
            if (arr[i] >= mid) {
                a[i] = 1;
            }
            else {
                a[i] = -1;
            }
        }
        for (int i=1; i<n; ++i) {
            a[i] += a[i-1];
        }
        int maxsum = 0;
        int mindiff = 0;
        for (int i=k-1; i<n; ++i) {
            if (i != k-1) {
                mindiff = min(mindiff, a[i-k]);
            }
            maxsum = max(maxsum, a[i]-mindiff);
        }
        if (maxsum > 0) {
            l = mid;
        }
        else {
            r = mid-1;
        }
    }
    cout << l;
}