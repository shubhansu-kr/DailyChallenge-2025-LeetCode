// https://leetcode.com/problems/apply-operations-to-an-array/?envType=daily-question&envId=2025-03-01

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
    vector<int> applyOperations(vector<int>& nums) {
        
        for(int i = 0 ; i < nums.size()-1 ; i++){
                if(nums[i]==nums[i+1]){
                    nums[i]*=2;
                    nums[i+1]=0;
                }
                else
                continue ;
            
        }
            int index = 0; 
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[i], nums[index]); 
                index++; 
            }
        }
        return nums;
    }
};

int main () {
    
    return 0;
}
