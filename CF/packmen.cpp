#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string board;
    cin >> board;
    vector<int> pack;
    vector<int> food;
    for (int i=0; i<n; ++i) {
        if (board[i] == '*') {
            food.push_back(i);
        }
        else if (board[i] == 'P') {
            pack.push_back(i);
        }
    }
    int l = 0;
    int r = n + (n+1)/2;
    while (l<r) {
        int mid = (l+r-1)/2;
        bool works = false;
        set<int> eat;
        for (int i=0; i<food.size(); ++i) {
            eat.insert(food[i]);
        }
        for (int i=0; i<pack.size(); ++i) {
            bool hasLeft = false;
            auto it = eat.begin();
            if (*it < pack[i]) {
                hasLeft = true;
            }
            int lefdis = 0;
            if (hasLeft && pack[i] - *it <= mid) {
                lefdis = pack[i] - *it; 
            }
            else if (hasLeft && pack[i] - *it > mid) {
                break;
            }
            while (it != eat.end() && pack[i] > *it) { //erase all the left
                eat.erase(it++);
            }
            auto it1 = it;
            auto it2 = it;
            int rightdis1 =mid-lefdis*2;
            int g1,g2;
            g1 = g2 =0;
            while (it1 != eat.end() && abs(pack[i]-*it1) <= rightdis1) {
                ++it1;
                ++g1;
            }
            int rightdis2 = (mid-lefdis)/2;
            if (!hasLeft) {
                rightdis2 = mid;
            }
            while (it2 != eat.end() && abs(pack[i]-*it2) <= rightdis2) {
                ++it2;
                ++g2;
            }
            if (g2 > g1) {
                while (it!= eat.end() && it != it2) {
                    eat.erase(it++);
                }
            }
            else {
                while (it!=eat.end() && it != it1) {
                    eat.erase(it++);
                }
            }
            if (eat.size() == 0) {
                works = true;
                break;
            }
        }
        if (works) {
            r = mid;
        }
        else {
            l= mid+1;
        }
    }
    cout << l;
}
