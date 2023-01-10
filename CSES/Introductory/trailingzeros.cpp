#include <bits/stdc++.h>
using namespace std;

int n,c1,c2;

int main() {
    cin >> n;
    int x=5;
    while (x<=n) {
        c1 += (n/x);
        x*=5;
    }
    cout <<c1;
}