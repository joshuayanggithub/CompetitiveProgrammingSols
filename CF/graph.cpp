#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f first
#define s second

const int maxn = 100005; //100001
int n,m;
vector<pair<int,int>> adj[maxn];
bool vis[maxn];
double ans[maxn];
double x;
bool foundx;
bool works = true;
pair<double,double> equation[maxn]; //ax + b
vector<int> cur;

void replace() {
    for (int i=0; i<cur.size(); ++i) {
        equation[cur[i]].s =  (double) x * equation[cur[i]].f + equation[cur[i]].s;
        equation[cur[i]].f = 0;
        ans[cur[i]] = equation[cur[i]].s;
    }
}
void dfs(int node) {
    vis[node] = true;
    cur.push_back(node);
    for (auto next: adj[node]) {
        if (!works) {
            return;
        }
        int neigh = next.f;
        int type = next.s;
        double newa = -equation[node].f; //-ax
        double newb = (double) type - equation[node].s; // 2 - b or 1-b
        if (!vis[neigh]) {
            equation[neigh].f = newa; 
            equation[neigh].s = newb; 
            dfs(neigh);
        }
        else if (vis[neigh]) {
            if (abs(newa-equation[neigh].f) <1e-9 && abs(newb-equation[neigh].s) < 1e-9) {
                continue;
            }
            if (abs(newa-equation[neigh].f) <1e-9 && abs(newb-equation[neigh].s) >= 1e-9) {
                works = false;
                return;
            }
            x = double (newb-equation[neigh].s) / (equation[neigh].f-newa); //ax + b = cx + d
            replace();
            //cur.clear(); //need this?
            /*if (foundx) {
                double otherx = double (type - equation[node].s - equation[neigh].s) / (equation[node].f + equation[neigh].f);
                if (abs(x - otherx) < 1e-9) {
                    works = false;
                    return;
                }
            }
            else { // (ax+b) + (cx+d) = 2 or 1
                x = double (type - equation[node].s - equation[neigh].s) / (equation[node].f + equation[neigh].f);
            }*/
        }
    }
    if (!works) {
        return;
    }
}
signed main() {
    cin >> n >> m;
    int a,b,c;
    for (int i=0; i<m; ++ i) {
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for (int i=1; i<=n; ++i) {
        if (vis[i]) {
            continue;
        }
        equation[i] = {1,0}; //x + 0
        dfs(i);
        bool allzero = true;
        for (int j=0; j<cur.size(); ++j) {
            if (equation[cur[j]].f != 0) {
                allzero = false;
            }
        }
        if (!allzero) {
            vector<double> v;
            for (int j=0; j<cur.size(); ++j) {
                if (equation[cur[j]].f == 1) {
                    v.push_back(-equation[cur[j]].s);
                }
                else {
                    v.push_back(equation[cur[j]].s);
                }
            }
            sort(v.begin(), v.end());
            if (v.size() % 2 == 0) { //1 2 3 4 5 6
                x = (v[(v.size()-1)/2] + v[(v.size()-1)/2+1])/2;
            }
            else {
                x = v[(v.size()-1)/2];
            }
        }
        for (int j=0; j<cur.size(); ++j) {
            if (ans[cur[j]] == 0) {
                ans[cur[j]] = (double) x * equation[cur[j]].f + equation[cur[j]].s;
            }
        }
        //reset
        foundx = false;
        x = 0;
        cur.clear();
        if (!works) {
            break;
        }
    }
    if (works) {
        cout << "YES" << "\n";
        for (int i=1; i<=n; ++i) {
            cout << ans[i] << " ";
        }
    }
    else {
        cout <<"NO";
    }
    cout << "\n";
}


//x, 1-x, 2-x, 1+x