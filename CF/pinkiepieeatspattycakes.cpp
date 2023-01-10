#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int main() {
    int t;
    cin >> t;
    for (int j=0; j<t; ++j) {
        int n;
        cin >> n;
        int fillings[n+1];
        vector<int> num (n+1);
        for (int i=1; i<=n; ++i) {
            cin >> fillings[i];
            ++num[fillings[i]];
        }
        vector<int> multiple;
        for (int i=1; i<=n; ++i) {
            if (num[i] > 1) {
                multiple.push_back(num[i]);
            }
        }
        sort(multiple.begin(),multiple.end(), greater<int>());
        int max = multiple[0];
        int maxspacing = (n-max) / (max-1);
        int l = 0;
        int r= maxspacing;
        while (l<r) {
            int mid = (l+r+1)/2; //check out later
            int pos = 1; //least position not taken
            vector<bool> vis(n+1); //if visited this position
            bool works = true;
            for (int i=0; i<multiple.size(); ++i) {
                while (vis[pos]==true) {
                    ++pos;
                }
                int maxpos = pos + (mid +1)*(multiple[i]-1);
                if (maxpos > n) {
                    works = false;
                    break;
                }
                for (int newp=pos; newp<=maxpos; newp+= (mid+1)) {
                    vis[newp] = true; 
                }
                ++pos;
            }
            int extra = n - (mid) * (max-1) - max;
            if (extra >= mamxspacing * (max-1)) {
                works = true;
            }
            if (works == true) {
                l = mid;
            }
            else {
                r = mid-1;
            }
        }
        cout << l << endl;
    }
}