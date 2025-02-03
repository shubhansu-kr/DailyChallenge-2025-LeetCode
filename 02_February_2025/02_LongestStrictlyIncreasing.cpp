// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/?envType=daily-question&envId=2025-02-03

#include <bits/stdc++.h>
using namespace std ;

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution 
{
    public:
    int longestMonotonicSubarray(vector<int>& nums)
    {
        int n=nums.size();
        int incr=1;
        int decr=1;
        int result=1;

        for(int i=1;i<n;i++)
        {
            if(nums[i]>nums[i-1])
            {
                incr++;
                decr=1;
                result=max({incr,decr,result});
            }
            else if(nums[i]<nums[i-1])
            {
                decr++;
                incr=1;
                result=max({incr,decr,result});
            }
            else
            {
                incr=1;
                decr=1;
            }
        }
        return result;
    }
};

int main () {
    
    return 0;
}
