// https://leetcode.com/problems/smallest-subarrays-with-maximum-bitwise-or/?envType=daily-question&envId=2025-07-29

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
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> res(nums.size() , -1);
        vector<int> lastSeen(32 , -1);
        for(int i=nums.size()-1 ; i>=0 ; i--){
            int x = nums[i];
            int bitPos = 31;
            while(x>0){
                if((x&1)==1)  lastSeen[bitPos] = i;
                x = x>>1;
                bitPos--;
            }
            int maxIdx = -1;
            for(int j=0 ; j<32 ; j++){
                maxIdx = max(maxIdx , lastSeen[j]);
            }
            if(maxIdx == -1)    maxIdx = i;
            res[i] = maxIdx-i+1;
        }
        return res;
    }
};

int main () {
    
    return 0;
}