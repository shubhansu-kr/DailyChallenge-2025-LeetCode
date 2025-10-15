// https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/?envType=daily-question&envId=2025-10-15

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
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        
        left[0] = 1;
        int prev = nums[0];
        for(int i = 1;i<n;i++){
            if(nums[i]>prev){
                left[i] += left[i-1];
            }
            prev = nums[i];
        }
        prev = nums[n-1];
        for(int i = n-2;i>=0;i--){
            if(nums[i] < prev){
                right[i] += right[i+1];
            }
            prev = nums[i];
        }
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            ans = max(ans,min(left[i],right[i+1]));
        }
        return ans;
    }
};


int main () {
    
    return 0;
}