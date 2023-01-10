#include<bits/stdc++.h>
using namespace std;

int main() {
    freopen("helpcross.in","r",stdin);
    freopen("helpcross.out","w",stdout);
    int c,n;
    cin >> c >> n;
    int chickens[c];
    for (int i=0; i<c; ++i) {
        cin >> chickens[i];
    }
    pair<int,int> cows[n];
    for (int i=0; i<n; ++i){
        cin >> cows[i].first >> cows[i].second;
    }
    sort(cows,cows+n);
    sort(chickens,chickens+c);
    multiset<int> endtimes;
    int p2 = 0;
    int ans = 0;
    for (int p1=0; p1<c; ++p1) {
        //loop until starting point is greater or reached end of bound 
        while (p2<n && chickens[p1] >= cows[p2].first) {
            endtimes.insert(cows[p2].second);    //add to set of end times
            ++p2;
        }
        //delete if not within range
        while (!endtimes.empty() && *endtimes.begin() < chickens[p1]) {
            endtimes.erase(*endtimes.begin());
        }
        //find the smallest endtime thats within range
        //delete the one within range
        //add to answer
        if (!endtimes.empty() && *endtimes.begin() >= chickens[p1]) {
            endtimes.erase(endtimes.begin());
            ++ans;
        }
    }
    cout << ans;
}