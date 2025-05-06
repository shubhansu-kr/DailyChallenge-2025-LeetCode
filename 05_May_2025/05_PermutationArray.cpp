// https://leetcode.com/problems/build-array-from-permutation/?envType=daily-question&envId=2025-05-06

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
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans; 
        for(int i = 0; i < nums.size(); ++i) {
            ans.emplace_back(nums[nums[i]]);
        }
        return ans; 
    }
};

int main () {
    
    return 0;
}