// https://leetcode.com/problems/maximum-erasure-value/?envType=daily-question&envId=2025-07-22

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
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int curr_sum = 0, max_sum = 0, l = 0;
        for (int num : nums) {
            while (seen.find(num) != seen.end()) {
                curr_sum -= nums[l];
                seen.erase(nums[l]);
                ++l;
            }
            curr_sum += num;
            seen.insert(num);
            max_sum = max(max_sum, curr_sum);
        }
        return max_sum;
    }
};

int main () {
    
    return 0;
}