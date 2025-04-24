// https://leetcode.com/problems/count-complete-subarrays-in-an-array/?envType=daily-question&envId=2025-04-24

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
    int countCompleteSubarrays(vector<int>& nums) {
        int k = unordered_set<int>(nums.begin(),nums.end()).size();
        unordered_map<int, int> mpp;
        int left = 0; int res = 0;

        for (int i = 0; i < nums.size(); ++i) {
            mpp[nums[i]]++;
            while (mpp.size() == k) {
                res += nums.size() - i;  
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
        }
        return res;
    }
};

int main () {
    
    return 0;
}