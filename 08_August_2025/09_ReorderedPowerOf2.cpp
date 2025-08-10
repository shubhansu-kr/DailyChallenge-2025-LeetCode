// https://leetcode.com/problems/reordered-power-of-2/?envType=daily-question&envId=2025-08-10

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        long c = counter(n);
        for (int i = 0; i < 32; i++)
            if (counter(1 << i) == c) return true;
        return false;
    }

    long counter(int n) {
        long res = 0;
        for (; n; n /= 10) res += pow(10, n % 10);
        return res;
    }
};

int main () {
    
    return 0;
}