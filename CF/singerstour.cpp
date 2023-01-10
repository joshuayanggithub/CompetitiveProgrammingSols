#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int j=0; j<t; ++j) {
        long long n;
        cin >> n;
        long long sum = 0;
        long long total[n];
        long long singers[n];
        for (int i=0; i<n; ++i) {
            cin >> total[i];
            sum += total[i];
        }
        bool work = true;
        long long num = n * (n+1) /2;
        if (sum % num != 0) {
            work = false;
        }
        long long xyz = sum / num;
        //nbrpo
        long long singersum = 0;
        for (int i=0; i<n; ++i) {
            int r = i;
            int l = (i-1+n)%n;
            long long diff = total[r] - total[l];
            singers[i] = (xyz-diff) / (n);
            singersum += singers[i];
            if (singers[i]<= 0) 
                work = false;
        }
        if (singers[0] == 0) {
            work = false;
        }
        if (singersum != xyz) {
            work = false;
        }
        if (work == true) {
            cout << "YES" << "\n";
            for (int i=0; i<n; ++i) {
                cout << singers[i] << " ";
            }
            cout << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }   
}