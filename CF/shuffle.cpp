#include <bits/stdc++.h>
using namespace std;

/*long long nchoosek(int n, int k) {
    long long product = 1;
    for (long long i=n-k+1; i<=n; ++i) {
        product = product * i;
    }
    for (long long i=1; i<=k; ++i){
        product /= i;
    }
    return product;
}*/
int main() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> ones;
    for (int i=0; i<n; ++i) {
        if (s[i] == '1') {
            ones.push_back(i);
        }
    }
    //calcualting choose function without overflow!
    vector<vector<int>> C(n + 1);
    for(int i = 0; i <= n; i++)
    {
        C[i].resize(i + 1);
        C[i][0] = C[i][i] = 1;
        for(int j = 1; j < i; j++)
            C[i][j] = (C[i - 1][j]%998244353 + C[i - 1][j - 1]%998244353)%998244353;
    }
    int num = ones.size();
    long long ans = 0;
    int previousr = 0;
    for (int i=0; i<=num-k; ++i) {
        int l,r;
        if (i != 0)
            l = ones[i-1]+1;
        else 
            l = 0;
        if (i+k-1<num-1)  //if i+k-1 < num-1 kth index will be less than max index
            r = max(ones[i],ones[i+k]-1);
        else
            r = n-1;
        long long total = r-l+1;
        long long numways = C[total][k];
        if (i==0) {
            ans = (ans + numways % 998244353) % 998244353;
        }
        else {
            long long notoverlapped = r - previousr;
            long long overlapped = C[total-notoverlapped][max(0,k-1)];
            ans = (ans + (numways - overlapped+998244353)%998244353)%998244353;
        }
        previousr = r;
    }
    if (ans < 0 ) {
        cerr <<"-";
    }
    if (ones.size() < k) {
        ans = 1;
    }
    while (ans < 0) {
        ans += 998244353;
    }
    cout << ans;
}