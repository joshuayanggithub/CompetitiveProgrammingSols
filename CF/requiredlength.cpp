#include <bits/stdc++.h>
using namespace std;
//thoughts: got hinted, this is an interesting what seems unsolvable within time limit type of problem at first
#define ll long long

ll n,x;

int main() {
    cin >> n >> x;
    map<ll,ll> vis;
    vis[x] = 0;
    queue<ll> q;
    q.push(x);
    ll ans = 100;
    while (!q.empty()) {
        ll num = q.front(); q.pop();
        string s = to_string(num);
        int len = s.length();
        if (len == n) {
            ans = min(ans, vis[num]);
        }
        else if (len > n) {
            break;
        }
        for (int i=0; i<len; ++i) {
            if (s[i] == '1') {continue; }
            ll next = num * (s[i] - '0');
            if (vis[next] != 0) {
                //vis[next] = min(vis[num] + 1, vis[next]);
            }
            if (!vis[next]) { //0
                vis[next] = vis[num] + 1;
                q.push(next);
            }
        }
    }
    if (ans == 100)
        cout << -1;
    else
        cout << ans;
}
