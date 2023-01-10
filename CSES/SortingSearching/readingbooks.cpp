#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n, sum,cur,off,cur2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<ll> books(n);
    for (int i=0; i<n; ++i) {
        cin >> books[i];
        sum += books[i];
    } 
    sort(books.begin(),books.end(),greater<int>());
    if (books[0]>sum-books[0]) {
        cout <<2*books[0];
    }
    else
        cout << sum;
}