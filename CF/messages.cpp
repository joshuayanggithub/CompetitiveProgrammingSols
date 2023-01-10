#include <bits/stdc++.h>
using namespace std;

bool sortsecond(pair<int,int> p1, pair<int,int> p2) {
    return p1.second > p2.second;
}
int main() {
    int n;
    cin >> n;
    pair<int,int> m[n];
    for (int i=0; i<n; ++i) {
        cin >> m[i].first >> m[i].second;
    }
    sort(m,m+n);
    vector<pair<int,int>> messages;
    for (int i=0; i<n; ++i) {
       if (i == 0 || m[i].first != m[i-1].first) {
           messages.push_back({m[i].first,m[i].second});
       }
       else {
           messages[messages.size()-1].second += m[i].second;
       }
    }
    sort(messages.begin(),messages.end(),sortsecond);
    int psums[messages.size()];
    psums[0] = 0;
    for (int i=0; i<messages.size(); ++i) {
        if (i!= 0) {
            psums[i] = psums[i-1];
        }
        psums[i] += messages[i].second;
    }
    int ans = 0;
    int prev = 0;
    for (int i=0;i<messages.size(); ++i) {
        int k = i+1;
        int l = 0;
        int r = messages.size()-1;
        while (l<r) {
            int mid = (l+r+1)/2;
            if (messages[mid].second >= k) {
                l = mid;
            }
            else {
                r = mid-1;
            }
        }
        if (l>i) {
            l = i;
        }
        int sum = psums[i]-psums[l];
        int total = sum + (l+1)*k;
        if (i!= 0 && total * (k-1) < prev*k) {
            ans = k-1;
            break;
        }
        prev = total;
        ans = k;
    }
    cout << ans << "\n";
    for (int i=0; i<ans; ++i) {
        cout << messages[i].first << " ";
    }
}