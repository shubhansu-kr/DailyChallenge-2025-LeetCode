// https://leetcode.com/problems/bitwise-xor-of-all-pairings/?envType=daily-question&envId=2025-01-16

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
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;

        int x=nums1.size();
        int y=nums2.size();

        if(x&1){
            for(auto i : nums2){
                ans=ans^i;
            }
        }

        if(y&1){
            for(auto i : nums1){
                ans=ans^i;
            }
        }

        return ans;
    }
};

int main () {
    
    return 0;
}
