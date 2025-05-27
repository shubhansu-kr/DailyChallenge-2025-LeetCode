// https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/?envType=daily-question&envId=2025-05-27

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
    int differenceOfSums(int n, int m) {
        int cnt1 = 0, cnt2 = 0;
        
        for(int i = 1; i <= n; i++)
        {
            if(i% m != 0)
            {
                cnt1 += i;
            }
            else
            {
                cnt2 += i;
            }
        }
        return cnt1 - cnt2;
    }
};

int main () {
    
    return 0;
}