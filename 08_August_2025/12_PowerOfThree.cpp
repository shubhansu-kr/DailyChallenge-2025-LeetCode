// https://leetcode.com/problems/power-of-three/?envType=daily-question&envId=2025-08-13

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
    bool isPowerOfThree(int n) {
        return n>0 && 1162261467 % n == 0 ;
    }
};

int main () {
    
    return 0;
}