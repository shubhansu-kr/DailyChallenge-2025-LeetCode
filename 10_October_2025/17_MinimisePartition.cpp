// https://leetcode.com/problems/maximize-the-number-of-partitions-after-operations/?envType=daily-question&envId=2025-10-17

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
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        nums[0] -= k;
        int i = 1;
        while(i<n){
            int curr = nums[i];
            int f = max(curr-k, nums[i-1]+1);
            while(i<n && nums[i]==curr){
                nums[i] = min(f, curr+k);
                f++;
                i++;
            }
        }
        map<int,int>mp;
        for(auto i:nums) mp[i]++;
        return mp.size();
    }
};

int main () {
    
    return 0;
}