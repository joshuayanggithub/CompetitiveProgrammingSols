#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string board;
    cin >> board;
    vector<int> pack;
    vector<int> eat;
    for (int i=0; i<n; ++i) {
        if (board[i] == '*') {
            eat.push_back(i);
        }
        else if (board[i] == 'P') {
            pack.push_back(i);
        }
    }
    int l = 0;
    int r = n;
    while (l<r) {
        int mid = (l+r-1)/2;
        bool works = false;
        set<int> food;
        for (int i=0; i<eat.size(); ++i) {
            food.insert(eat[i]);
        }
        for (int i=0; i<pack.size(); ++i) {
            auto leftmost = lower_bound(food.begin(), food.end(),pack[i]-mid);
            int left = *leftmost;
            int dis = max(pack[i] - left,0);
            int max1 = mid-2*dis;
            auto rightmost1 = upper_bound(food.begin(), food.end(), pack[i]+max1);
            --rightmost1;
            int max2 = (mid - dis)/2;
            if (dis == 0) {
                max2 = mid - dis;
            }
            auto rightmost2 = upper_bound(food.begin(), food.end(), pack[i]+ max2);
            --rightmost2;
            int right = max(*rightmost1,*rightmost2);
            if (*leftmost - pack[i] > mid) {
                continue;
            }
            auto it = leftmost;
            while (*it != right) {
                food.erase(it++);
            }
            food.erase(it);
            if (food.size() == 0) {
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