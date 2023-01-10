#include <bits/stdc++.h>
using namespace std;

string ans = "";

void addb(long long num) {
    for (int i=0; i<num; ++i) {
        ans += "b";
    }
}
int main() {
    int t;
    cin >> t;
    for (int j=0; j<t; ++j) {
        int n,k;
        long long x;
        cin >> n >> k >> x;
        string s;
        ans = "";
        cin >> s;
        long long maxp = 1;
        //int start = 0;
        long long counter = 0;
        int numast = 0;
        for (int i=0; i<n; ++i) {
            if (s[i] == '*') {
                ++counter;
            }
            if (s[i] != '*' || (i == n-1 && s[i] == '*')){ 
                ++numast;
                if (counter != 0) {
                    maxp *= ((long long) k * counter + 1); //num of choices
                }
                counter = 0;
            }
        }
        long long rem = x;
        int numast2 = 0;
        counter = 0;
        long long left = x; //num of permutations left
        bool fillup = false;
        for (int i=0; i<n; ++i) {
            if (s[i] == '*') {
                ++counter;
            }
            if (s[i] != '*' || (i == n-1 && s[i] == '*')) {
                ++numast2;
                if (counter != 0) {
                    maxp /= ( (long long ) k * counter  +1 ); //how much permutations each asterisk in this range would contribute
                    long long numb = max((long long) 0, (long long) ceil( (long double) left/ maxp) - 1); //num of bs to take
                    if (fillup) {
                        numb = counter * k ;
                    }
                    if (left % maxp == 0) {
                        fillup = true;
                    }
                    addb(numb);
                    left = left % maxp;
                }
                if (s[i] == 'a') {
                    ans += "a";
                }
                counter = 0;
            }
        }
        cout << ans << endl;
    }
}