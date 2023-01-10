#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second 

int main() {
	// the following line creates/overwrites the output file
    int k,m,n;
    cin >> k >> m >> n; 
    vector <pair<int, int>> patches (k);
    vector<long long> psum; //sum of patch tastiness
    for (int i=0; i<k; ++i) {
        cin >> patches[i].f >> patches[i].s;
    }
    sort(patches.begin(), patches.end());
    psum.push_back(0); //1 indexed
    for (int i=0; i<k; ++i) {
        psum.push_back( psum[psum.size()-1] + (long long) (patches[i].s));
    }
    vector <int> placed (m+2); //farmer nhoj
    placed[0] = (int) (-10e9-1);
    placed[m+1] = (int) (2*10e9+1); //to deal with edge cases, we will assume farmer nhoj has placed at these far ends, which will never be close
    for (int i=1; i<=m; ++i) {
        cin >> placed[i];
    }
    sort(placed.begin(),placed.end());
    int ind = 0;
    vector <long long> best;
    for (int i=0; i<=m; ++i) { //loop through each range 0-1 to m-m+1
        int leftplaced = placed[i];
        int rightplaced= placed[i+1];
        int l = INT_MAX; //basically the leftmost and rightmost patch indexes
        int r = INT_MIN;
        long long totaltasty = 0;
        while (patches[ind].f > leftplaced && patches[ind].f < rightplaced) {
            totaltasty += (long long) (patches[ind].s);
            l = min(l, ind); 
            r = max(r, ind);
            ++ind;
        }
        long long best1 = 0;
        int right = l; //rightmost patch that you can gurantee you can get
        for (int j=l; j<=r; ++j) { //j is the leftmost patch within your grasp
            long long disg = ((long long) (patches[j].f) - leftplaced-1)/2; //distance from patch to gurantee you have hold; rounds down
            long long cow = min( (long long) (patches[j].f) + disg , (long long) (rightplaced-1)); //place to the right of this patch so that it has priority over nhoj
            while ( right <= r ) {
                if (abs(cow - patches[right].f) < abs(rightplaced - patches[right].f)) {
                    ++right;
                }
                else {
                    break;
                }
            }
            --right; //we added one and then if it doesnt work we had an extra 1
            best1 = max((long long) (best1), psum[right+1] - psum[j-1+1]); //prefix sum for sum of all patches its also one indexed
        }
        best.push_back(best1); //you would be adding 0s if there was no patch in the range
        best.push_back(totaltasty - best1); //if u added a second time
    }
    sort(best.begin(), best.end());
    long long ans = 0;
    for (int i=best.size()-1; i>=best.size()-n; --i) {
        ans += best[i];
    }
    cout << ans;
}