// https://leetcode.com/problems/partition-equal-subset-sum/?envType=daily-question&envId=2025-04-07

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        for (int a : nums)
            sum += a;
        vector<vector<int>> dp(n+1, vector<int>(sum / 2 +1, -1));
        return (sum % 2) ? false : solve(nums, dp, sum / 2, n - 1);
    }

    bool solve(vector<int> &nums, vector<vector<int>> &dp, int k, int i)
    {
        if (k == 0)
            return true;
        if (i == 0)
            return k == nums[i];

        if (dp[i][k] != -1)
            return dp[i][k];

        bool pick = false;
        if (nums[i] <= k)
            pick = solve(nums, dp, k - nums[i], i - 1);
        if (pick)
            return pick;
        bool noPick = solve(nums, dp, k, i - 1);

        return dp[i][k] = (pick || noPick);
    }
};

int main () {
    
    return 0;
}