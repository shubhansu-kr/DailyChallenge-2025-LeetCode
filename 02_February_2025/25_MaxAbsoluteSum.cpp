// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/?envType=daily-question&envId=2025-02-26

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
    int maxsub(vector<int>& nums){
        int currsum=0,maxsum=INT_MIN;
        for(auto &el:nums) {
            currsum+=el;
            maxsum=max(maxsum,currsum);
            if(currsum<0) {
                currsum=0;
            }
        }
        return maxsum;
    }

    int minsub(vector<int>& nums){
        int currsum=0,minsum=INT_MAX;
        for(auto &el:nums){
            currsum+=el;
            minsum=min(minsum,currsum);
            if (currsum > 0) currsum = 0; 
        }
        return minsum;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int s1=maxsub(nums);
        int s2=minsub(nums);
        return max(abs(s1),abs(s2));
    }
};

int main () {
    
    return 0;
}
