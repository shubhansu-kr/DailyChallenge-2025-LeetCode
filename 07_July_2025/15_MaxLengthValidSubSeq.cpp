// https://leetcode.com/problems/find-the-maximum-length-of-valid-subsequence-i/solutions/6967044/dp-using-parities/?envType=daily-question&envId=2025-07-16

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
    int f(vector<int>& nums,int i,int prev,int n,vector<vector<int>>&dp,int bit)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        int pick=0,notPick=f(nums,i+1,prev,n,dp,bit);
        if(prev==-1 || (prev+nums[i])%2==bit)
        {
            pick=1+f(nums,i+1,nums[i]%2,n,dp,bit);
        }
        return dp[i][prev+1]=max(pick,notPick);
    }
    int maximumLength(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>odd(n,vector<int>(3,-1));
            vector<vector<int>>even(n,vector<int>(3,-1));
        return max(f(nums,0,-1,n,odd,1),f(nums,0,-1,n,even,0));
        
    }
};

int main () {
    
    return 0;
}