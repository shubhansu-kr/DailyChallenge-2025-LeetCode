// https://leetcode.com/problems/count-subarrays-of-length-three-with-a-condition/?envType=daily-question&envId=2025-04-27

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
    int countSubarrays(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int i=2, count = 0;
        while(i<nums.size()){
            if( (nums[i]+nums[i-2])*2 == nums[i-1] ) count++;
            i++;
        }
        return count;
    }
};

int main () {
    
    return 0;
}