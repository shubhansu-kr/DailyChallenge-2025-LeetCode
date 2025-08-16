// https://leetcode.com/problems/maximum-69-number/?envType=daily-question&envId=2025-08-16

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
    int maximum69Number (int num) {
        string nums = to_string(num);
        for (auto &it: nums){
            if (it == '6') {
                it = '9';
                break;
            }
        }
        return stoi(nums);
    }
};

int main () {
    
    return 0;
}