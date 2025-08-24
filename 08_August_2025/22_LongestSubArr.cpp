// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/?envType=daily-question&envId=2025-08-24

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
    int longestSubarray(vector<int>& nums) {
        int i = 0, j, k = 1;
        for (j = 0; j < nums.size(); ++j)
        {
            if (nums[j] == 0)
                k--;
            if (k < 0 && nums[i++] == 0)
                k++;
        }
        return j - i - 1;
    }
};

int main () {
    
    return 0;
}