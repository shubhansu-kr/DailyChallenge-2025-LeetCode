// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/?envType=daily-question&envId=2025-06-18

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
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i = 2; i < nums.size(); i += 3){
            if(nums[i] - nums[i - 2] > k) return {};
            ans.push_back({nums[i-2], nums[i-1], nums[i]});
        }
        return ans;
    }
};

int main () {
    
    return 0;
}