// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/?envType=daily-question&envId=2025-04-03

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        vector<int>mx_arr(n);
        int mx = 0;
        for(int i = n-1;i>=0;i--)
        {
            mx_arr[i] = mx;
            mx = max(mx,nums[i]);
        }
        long long lmx = 0;
        for(int i = 0;i<n;i++)
        {
            long long rmx = mx_arr[i];
            long long val = nums[i];
            ans = max(ans,rmx*(lmx-val));
            lmx = max(lmx,val);
        }
        return ans;
    }
};

int main () {
    
    return 0;
}