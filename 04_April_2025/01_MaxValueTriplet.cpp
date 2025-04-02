// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i/?envType=daily-question&envId=2025-04-02

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    public:
        long long maximumTripletValue(vector<int>& nums) {
            int n = nums.size();
            long long ans = 0, temp;
    
            for(int i = 0; i < n; ++i) {
                for(int j = i+1; j < n; ++j){
                    for(int k = j+1; k < n; ++k) {
                        temp = static_cast<long long>(nums[i] - nums[j]) * nums[k]; 
                        ans = max(temp, ans);
                    }
                }
            }
    
            return ans;
        }
    };
    

int main () {
    
    return 0;
}