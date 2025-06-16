// https://leetcode.com/problems/maximum-difference-between-increasing-elements/?envType=daily-question&envId=2025-06-16

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
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int sm = nums[0];
        int mx = -1;
        vector<int> small(n);
        for(int i=0;i<n;i++){
            if(sm >= nums[i]){
                small[i] = -1;
                sm = nums[i];
            }
            else{
                small[i] = sm;
            }
            if(small[i] != -1){
                mx = max(mx,nums[i] - small[i]);
            }
        }
        return mx;
    }
};

int main () {
    
    return 0;
}