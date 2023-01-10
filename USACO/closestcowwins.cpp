/*
#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

bool sortsec(pair<int,int> a, pair<int,int>b) {
    return a.s - b.s;
}

int main() {
    int k,m,n;
    cin >> k >> m >> n;
    vector <pair<int, int>> patches (n);
    for (int i=0;i<k;++i) {
        int a,b;
        cin >> a >> b;
        patches.push_back({a,b});
    }
    sort(patches.begin(), patches.end());
    vector <int> placed (n);
    for (int i=0; i<m; ++i) {
        cin >> placed[i];
    }
    sort(placed.begin(),placed.end());
    int p,l; //pointer for patches and closest placed cow
    p = l = 0;
    vector <pair<int,int>> closest (n);
    while (p<k) {
        int dis = INT_MAX;
        while (l<m) {
            if ( abs(patches[p].f-placed[l]) < dis) {
                if (placed[l] > patches[p].f) {
                    closest[p] = {-1,l};
                }
                else {
                    closest[p] = {l,-1};
                }
            }
            else if (abs(patches[p].f-placed[l]) == dis) {
                closest[p] = {closest[p].f, l};
            }
            if (placed[l] > patches[p].f) {
                break;
            }
            ++l;
        }
        l = min(l, m-1); //reset 
        ++p;
    }
    sort(closest.begin(), closest.end());
    vector <int> tastiness (n,0);
    int ind = 0;
    for (int i=0; i<n-1; ++i) {
        if (closest[i].f == -1 || closest[i].s == -1) {
            tastiness[ind] += patches[i].s;
        }
        else {
            for (int j=closest[i].f; j<closest[i].s; ++j) {
                if (j< patches[i].f) {
                    
                }
                else {

                }
            }
        }
    }
}
*/