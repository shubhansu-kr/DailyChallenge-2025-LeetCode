// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/?envType=daily-question&envId=2025-04-08

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> tSet;
        for(int i = nums.size()-1; i>=0; i--){
            int num = nums[i];
            if(tSet.count(num)){
                return i/3+1;
            }
            tSet.insert(num);
        }
        return 0;
    }
};

int main () {
    
    return 0;
}