// https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/?envType=daily-question&envId=2025-03-04

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
    bool checkPowersOfThree(int n) {
        while(n>0)
        {
            if(n%3==0)
            {
                n/=3;
            }
            else if(n%3==1)
            {
                n-=1;
            }
            else
            return false;
        }
        return true;
    }
};

int main () {
    
    return 0;
}
