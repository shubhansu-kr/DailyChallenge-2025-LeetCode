// https://leetcode.com/problems/neighboring-bitwise-xor/?envType=daily-question&envId=2025-01-17

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
    bool doesValidArrayExist(vector<int>& derived) {
        int xor1 = 0;
        for(int num:derived){
            xor1 ^= num;
        }
        if(xor1==0) return true;
        return false;
    }
};

int main () {
    
    return 0;
}
