// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/?envType=daily-question&envId=2025-10-14

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
    bool isStrictlyIncreasing(const vector<int>& nums, int start, int k) {
        for (int i = start; i < start + k - 1; i++) {
            if (nums[i] >= nums[i + 1]) return false;
        }
        return true;
    }

    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if (n < 2 * k) return false;
        if (k == 1) return true;

        for (int a = 0; a <= n - 2 * k; a++) {
            if (isStrictlyIncreasing(nums, a, k) &&
                isStrictlyIncreasing(nums, a + k, k)) {
                return true;
            }
        }
        return false;
    }
};

int main () {
    
    return 0;
}