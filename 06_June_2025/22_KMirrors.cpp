// https://leetcode.com/problems/sum-of-k-mirror-numbers/?envType=daily-question&envId=2025-06-23

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

typedef long long ll;
class Solution {
private:
    bool isMirror(ll num, int k) {
        ll mul = 1;
        while (mul * k <= num) mul *= k;

        for (; num; mul /= k * k) {
            int msd = num / mul;
            int lsd = num % k;
            if (msd != lsd) return false;

            num = (num - msd * mul - lsd) / k;
        }
        return true;
    }

    ll getPalindrome(ll num, bool odd) {
        ll tmp = (odd) ? num / 10 : num;
        while (tmp > 0) {
            num = num * 10 + tmp % 10;
            tmp /= 10;
        }
        return num;
    }
public:
    ll kMirror(int k, int n) {
        ll sum = 0, nextPrefix;

        for (ll prefix = 1; n > 0; prefix = nextPrefix) { 
            nextPrefix = prefix * 10;

            for (ll i = prefix; n > 0 && i < nextPrefix; ++i) {
                ll p = getPalindrome(i, true);
                if (isMirror(p, k)) {
                    sum += p;
                    --n;
                }
            }

            for (ll i = prefix; n > 0 && i < nextPrefix; ++i) {
                ll p = getPalindrome(i, false);
                if (isMirror(p, k)) {
                    sum += p;
                    --n;
                }
            }
        }
        return sum;
    }
};

int main () {
    
    return 0;
}