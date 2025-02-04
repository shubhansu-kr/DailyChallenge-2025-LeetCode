// https://leetcode.com/problems/maximum-ascending-subarray-sum/?envType=daily-question&envId=2025-02-04

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
    int maxAscendingSum(vector<int>& nums) {
        int ans = INT_MIN, runningSum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] > nums[i-1]) {
                runningSum += nums[i];
            } else {
                ans = max(ans, runningSum);
                runningSum = nums[i];
            }
        }
        ans = max(ans, runningSum);
        return ans;
    }
};

int main () {
    
    return 0;
}
