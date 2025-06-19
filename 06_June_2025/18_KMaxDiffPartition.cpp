// https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/?envType=daily-question&envId=2025-06-19

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
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0, base = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] - nums[base] <= k)
            {
                continue;
            }
            else
            {
                ++count;
                base = i;
            }
        }
        return ++count;
    }
};

int main () {
    
    return 0;
}