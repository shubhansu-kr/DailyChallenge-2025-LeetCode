// https://leetcode.com/problems/longest-nice-subarray/?envType=daily-question&envId=2025-03-18

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
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0,r = 0,curWindow = 0;
        int len = 0;

        while(r<nums.size()){
            while((curWindow & nums[r])!=0){
                curWindow ^= nums[l];
                l++;
                
            }
            len = max(len , r-l+1);
            curWindow |= nums[r];r++;
        }
        return len;
    }
};

int main () {
    
    return 0;
}
