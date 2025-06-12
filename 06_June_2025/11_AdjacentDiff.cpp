// https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/?envType=daily-question&envId=2025-06-12

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
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int max_diff=INT_MIN;
        for(int i=0;i<n-1;i++){
            max_diff=max(max_diff,abs(nums[i]-nums[i+1]));
        }
        max_diff=max(max_diff,abs(nums[0]-nums[n-1]));
        return max_diff;
    }
};

int main () {
    
    return 0;
}