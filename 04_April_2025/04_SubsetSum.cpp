// https://leetcode.com/problems/sum-of-all-subset-xor-totals/?envType=daily-question&envId=2025-04-05

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return accumulate(begin(nums), end(nums), 0, bit_or<int>()) << (nums.size() - 1);
    }
};

int main () {
    
    return 0;
}