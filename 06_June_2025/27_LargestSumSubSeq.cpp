// https://leetcode.com/problems/find-subsequence-of-length-k-with-the-largest-sum/?envType=daily-question&envId=2025-06-28

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
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> vals;  
        for (int i = 0; i < n; ++i) {
            vals.emplace_back(i, nums[i]);
        }
        sort(vals.begin(), vals.end(),
                [&](auto x1, auto x2) { return x1.second > x2.second; });
        sort(vals.begin(), vals.begin() + k);
        vector<int> res;  
        for (int i = 0; i < k; ++i) {
            res.push_back(vals[i].second);
        }
        return res;
    }
};

int main () {
    
    return 0;
}