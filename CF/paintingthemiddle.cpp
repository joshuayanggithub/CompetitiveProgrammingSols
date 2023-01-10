//OK I GAVE UP, IDK WHATS WRONG WITH MY SOL BUT I HAVE TO GET THAT GREEN CHECK MARK SO I TOOK THE EDITORIALS SOLUTION
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+7; 
int t,k,m,n; 
int a[maxn];
int r[maxn];
signed main() {	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		r[a[i]] = i;
	}
	int ans = 0;
	int r1,r2=0;
	for (int i=1;i<=n;i++) {
		r2 = 0;
		r1 = r[a[i]];
		if (r1==i) continue;
		int start = i;
		int cnt = 0;
		while (1) {
			for (int j=start;j<=r1;j++) {
				r2 = max(r2,r[a[j]]);
			}
			if (r2==r1) break;
			else {
				cnt++;
				start = r1;
				r1 = r2;
			}
		}
		if (r2==r[a[i]]) {
			ans += r2-i-1;
			i = r2;
		}
		else {
			ans += r2-i-cnt-1;
			i = r2;
		}
	}
	cout<<ans;
}

/*#include <bits/stdc++.h>
using namespace std;

int n;
int a[200001];
pair<int,int> p[200001];
vector<pair<int,int>> ranges;
int grid[200001];

int main() {
    cin >> n;
    // find all max pairings
    for (int i=1; i<=n; ++i) {
        cin >> a[i];
        if (p[a[i]].first == 0) {
            p[a[i]].first = i;
        }
        else {
            p[a[i]].second = i;
        }
    }
    for (int i=1; i<=n; ++i) {
        if (p[i].first != 0 && p[i].second != 0) {
            ranges.push_back({p[i].first,p[i].second});
        }
    }
    sort(ranges.begin(),ranges.end());
    //starting points will never be taken if they are not contained, , so find all endpoints that will be taken + non endpoints
    //if starting point of range is contained, take both
    int ans = 0;
    int r = 0;
    for (int i=0; i<ranges.size(); ++i) { 
        int l = i;
        r = i; 
        int maxr = ranges[i].second;
        int sub = 0;
        while (l<n && r<n) {
            bool went = false;
            maxr = ranges[l].second;
            while (r<ranges.size() && ranges[r].first <= ranges[l].second) {
                maxr = max(maxr, ranges[r].second);
                ++r;
                went = true;
            }
            if (went) 
                --r;
            if (maxr == ranges[l].second) {
                break;
            }
            else {
                ++sub;
                l = r;
            }
        }
        ans += maxr-ranges[i].first-sub-1;
        i = max(i,r);
    }

    cout << ans;
}
*/