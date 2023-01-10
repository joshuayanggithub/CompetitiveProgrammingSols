#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("berries.in","r",stdin);
    freopen("berries.out","w",stdout);
    int n,k;
    cin >> n >> k;
    int baskets[n];
    for (int i=0; i<n; ++i) {
        cin >> baskets[i];
    }
    sort(baskets,baskets+n,greater<int>());
    int maxb = 0;
    for (int b=1; b<=1000; ++b) {
        int elsie = 0;
        int i =0;
        int basketsc[n];
        for (int j=0; j<n; ++j) {
            basketsc[j] = baskets[j];
        }
        while (i<n && elsie != k/2) {
            if (elsie + basketsc[i]/b> k/2) {
                basketsc[i] -= (k/2 - elsie) * b;
                elsie = k/2;
            }
            else {
                elsie += basketsc[i]/b;
                basketsc[i] = basketsc[i]%b;
            }
            ++i;
        }
        if (elsie != k/2) {
            break;
        }
        elsie = i = 0;
        sort(basketsc,basketsc+n,greater<int>());
        while (i<n) {
            elsie += basketsc[i]/b;
            basketsc[i] = basketsc[i]%b;
            ++i;
        }
        sort(basketsc,basketsc+n,greater<int>());
        int counter = min(elsie,k/2);
        int sum = counter*b;
        if (counter < k/2) {
            for (int i=0; i<n; ++i) {
                sum += basketsc[i];
                counter++;
                if (counter == k/2) {
                    break;
                }
            }
        }
        maxb = max(maxb,sum);
    }
    cout << maxb;
}