// https://leetcode.com/problems/number-of-ways-to-split-array/?envType=daily-question&envId=2025-01-03

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
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        long long totalSum=0;
        int validSplit=0;
        long long sum=0;
        for(int i=0;i<n;i++)
            totalSum+=nums[i];
        for(int i=0;i<n-1;i++){
            sum+=nums[i];
            long long remSum=totalSum-sum;
            if(sum>=remSum)
                validSplit++;
        }
        return validSplit;
    }
};

int main () {
    
    return 0;
}
