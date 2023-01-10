#include <bits/stdc++.h>
using namespace std;

int n,m;

void solve() {
    cin >> n >> m;
    vector<int> tasks (m);
    vector<int> persontotasks (n+1);
    for (int i=1; i<=n; ++i) {
        //persontotasks[i].second = i;
    }
    for (int i=0; i<m; ++i) {
        cin >> tasks[i];
        persontotasks[tasks[i]]++;
    }
    sort(persontotasks.begin(), persontotasks.end(), greater<int>());
    int l=0, r = 2*m;
    while (l<r) {
        int t = (l+r)/2;
        long long leftover =0;
        for (int i=0; i<n; ++i) {
            int leftp = max(0, persontotasks[i]-t); 
            leftover += leftp;
            int timep = max(0, t-persontotasks[i]);
            leftover -= timep/2;
        }
        if (leftover <=0) {
            r = t;
        }
        else {
            l = t+1;
        }
    }
    cout << l << "\n";
}
int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}

/*for every worker create vector map of how many tasks are they proficient in
-binary search total time t
    -start from worker with greatest number of tasks to least
    -find which tasks a worker can do within time t
        -tasks which he is proficient at and which he can help others
    -if worker needs help then create structure to store number of unfinished tasks
    -if at last worker we still have unfinished tasks fail, otherwise this time works
*/
