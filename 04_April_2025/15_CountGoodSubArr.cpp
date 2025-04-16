// https://leetcode.com/problems/count-the-number-of-good-subarrays/?envType=daily-question&envId=2025-04-16

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res=0;
        int l=0;
        unordered_map<int,int> m;
        long long pairs=0;

        for(int i=0;i<nums.size();i++){

            m[nums[i]]++;
            int d = m[nums[i]];

            if(m[nums[i]]>=2){
                pairs = pairs  + d*(d-1)/2 - (d-1)*(d-2)/2 ; 
            }

            if(pairs >=k ){
                
                while(pairs >=k ){
                    int c = m[nums[l]];
                    m[nums[l]]--;
                    l++;
                    pairs = pairs  - c*(c-1)/2 + (c-1)*(c-2)/2 ; 

                }
                
            }
            res = res+l  ;
        }
        return res;
    }
};

int main () {
    
    return 0;
}