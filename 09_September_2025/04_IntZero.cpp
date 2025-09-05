// https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/?envType=daily-question&envId=2025-09-05

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();


class Solution {
    int countSetBits(long long n) {
    int count = 0;
    while (n > 0) {
        if (n & 1) { 
            count++;
        }
        n >>= 1; 
    }
    return count;
}
public:
    int makeTheIntegerZero(int num1, int num2) {
        int t=1;

        while(true){
            long long val=(long long)num1-t*(long long)num2;
            if(val<0) return -1;
            
            if(countSetBits(val)<=t && t<=val){
                return t;
            }
            t++;
        }
    }
};

int main () {
    
    return 0;
}