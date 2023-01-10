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
        int nummax = 1;
        for (int i=1; i<multiple.size(); ++i) {
            if (multiple[i] == max) {
                ++nummax;
            }
            else {
                break;
            }
        }
        int maxspacing = (n - max - nummax +1) / (max-1); //careful of 0 
        cerr << "\n";
        cout << maxspacing << "\n";
    }
}