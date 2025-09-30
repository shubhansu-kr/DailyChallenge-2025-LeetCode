// https://leetcode.com/problems/find-triangular-sum-of-an-array/?envType=daily-question&envId=2025-09-30

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
    int triangularSum(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];  
        vector<int>prev=nums;

        for(int i=0;i<n;i++){
            vector<int>temp(n-i-1,0);

            for(int j=1;j<prev.size();j++){
                temp[j-1]=(prev[j-1]+prev[j])%10;
            }

            prev=temp;
        }

        return prev[0];
    }
};

int main () {
    
    return 0;
}