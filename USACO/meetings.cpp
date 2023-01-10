#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int w,x,d;
    int mindis;
};

bool operator<(const Edge& e,const Edge& e2) {
        return e.mindis < e2.mindis;
}

bool comp(const Edge& e,const Edge& e2) {
        return e.x < e2.x;
}

int n,l;
Edge pos[500001];
int leftcows[500001];
int rightcows[500001];

int main() {
    freopen("meetings.in","r",stdin);
    freopen("meetings.out","w",stdout);

    cin >> n>> l;
    int left = INT_MAX;
    int right = -1;
    int lefti = 0;
    int righti = 0;
    int total = 0;
    for (int i=0; i<n; ++i) {
        cin >> pos[i].w >> pos[i].x >> pos[i].d;
        if (pos[i].d == -1) {
            pos[i].mindis = pos[i].x;
        }
        else {
            pos[i].mindis = l-pos[i].x;
        }
        total += pos[i].w;
    }   
    int sofar = 0;
    sort(pos,pos+n,comp);
    for (int i=0; i<n; ++i) {
        if (i!= 0) {
            leftcows[i] = leftcows[i-1];
            rightcows[i] = rightcows[i-1];
        }
        if (pos[i].d == -1) {
            leftcows[i]++;
        }
        else {
            rightcows[i]++;
        }
    }
    sort(pos,pos+n);
    for (int i=0; i<n; ++i) {
        if (pos[i].d == -1 && pos[i].x > right) {
            righti = i;
            right = pos[i].x;
        }
        else if (pos[i].d == 1 && pos[i].x < left) {
            lefti = i;
            left = pos[i].x;
        }
    }   
    int ans = 0;
    for (int i=0; i<n; ++i) {
        if (pos[i].d == 1) {
            swap(pos[i].w,pos[righti].w);
        }
        else {
            swap(pos[i].w,pos[lefti].w);
        }
        sofar += pos[i].w;
        if (sofar * 2 >= total) {
            ans = i+1;
            break;
        }
    }
    cout << ans;
}