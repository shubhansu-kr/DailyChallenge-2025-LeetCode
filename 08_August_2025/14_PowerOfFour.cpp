// https://leetcode.com/problems/power-of-four/?envType=daily-question&envId=2025-08-15

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
    bool isPowerOfFour(int n) {
        return (n > 0 && !(n & (n - 1)) && (n - 1) % 3 == 0);
    }
};

int main () {
    
    return 0;
}